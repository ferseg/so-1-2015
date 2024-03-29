#include "../Headers/socket.h"


int testConnection(){
    int sock;
    struct sockaddr_in server;
    
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
        return 0;
    }
    
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 0;
    }
    close(sock);
    return 1;
}

void sendDataToServer(char *message){
    int sock;
    struct sockaddr_in server;
    
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
 
    //Connect to remote server
    connect(sock , (struct sockaddr *)&server , sizeof(server));
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
    }
    close(sock);
}

void clearStrArr(char arr[], int len) {
    while(--len > -1) {
        arr[len] = 0;
    }
}

/* Thread for filling the queue */
void *sendDataToQueue(void *cpuSch){
    cpuScheduler_t *cpu = (cpuScheduler_t *) cpuSch; 
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    //puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
     
    //Bind
    bind(socket_desc,(struct sockaddr *)&server , sizeof(server));
    //puts("bind done");
     
    //Listen
    listen(socket_desc , 3);
     
    //Accept and incoming connection
    //puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
     
    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    //puts("Connection accepted");
    //Receive a message from client
    char client_message[MESSAGE_LEN];
    pthread_t *thread = malloc(sizeof(pthread_t));
    int lastId = -1;
    while((cpu->running == RUNNING) && (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) > 0){
        ////puts("Connection accepted");
        clearStrArr(client_message, MESSAGE_LEN);

        recv(client_sock , client_message , MESSAGE_LEN, 0);

        int strLen = strlen(client_message);


        if((strLen == 1) || (strLen == 4)){
            //////////////////////////////////////////////////////////
            // algoritmo para ordenar
            int algorithm = atoi(client_message);
            if (strLen == 4) {
                //puts("ENTERED");
                cpu->running = STOP_WHEN_QUEUE_IS_EMPTY;
                break;
            }
            else {
                cpu->algorithm = algorithm > ROUND_ROBIN ? ROUND_ROBIN : algorithm;
                cpu->quantum = algorithm - ROUND_ROBIN;
                pthread_create(&thread, NULL, initCPU, (void *) cpu);
            }
            //////////////////////////////////////////////////////////
        }
        else{
            int id,burst,priority;
            getTokens(client_message,&id,&burst,&priority);
            if(lastId == id) {
                continue;
            }
            lastId = id;
            //////////////////////////////////////////
            process *np = newProcess(id, burst, priority);
            pthread_mutex_lock(&lock);
            insertProcess(cpu->ready, np, cpu->algorithm);
            pthread_mutex_unlock(&lock);
            //////////////////////////////////////////
        }
    }
    pthread_join(thread, NULL);
    pthread_exit(EXIT_WO_ERROR);
}

void getTokens(char *str,int *id,int *burst, int *priority){
    char * pch;
    pch = strtok (str," ,.-");
    *id = atoi(pch);
    pch = strtok (NULL, " ,.-");
    *burst = atoi(pch);
    pch = strtok (NULL, " ,.-");
    *priority = atoi(pch);
}