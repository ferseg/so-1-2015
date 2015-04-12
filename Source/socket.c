#include "../Headers/socket.h"
#include "../Headers/process.h"

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
    close(socket);
    return 1;
}

void sendDataToServer(char *message){
    int *sock;
    struct sockaddr_in *server = getServer(sock);
    
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
        return 1;
    }
    close(socket);
}

/*
 * This will handle connection for each client
 * */
void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    char client_message[2000];
     
    //Receive a message from client
    while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 ){
        int id,burst,priority;
        getTokens(client_message,&id,&burst,&priority);
        printf("%d %d %d\n",id,burst,priority);
        newProcess(id,burst,priority);
        //aquí debería de insertar en la  cola
        
    }
    fflush(stdout);
    free(socket_desc);
    return 0;
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