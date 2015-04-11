#include "../Headers/client.h"

client* newClient(int pType, int pSortingMethod){
	client *nc = malloc(sizeof(client));
	nc->type = pType;
	nc->sortingMethod = pSortingMethod;
	nc->status = 0;
	return nc;
}

int getRandomNumber(int pMinNum, int pMaxNum){
    return (rand() % (pMaxNum - pMinNum + 1)) + pMinNum;
}

void createSocket(){
	int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
     
    puts("Connected\n");
     
    //keep communicating with server
    while(1)
    {
        printf("Enter message : ");
        scanf("%s" , message);
         
        //Send some data
        if( send(sock , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
         
        //Receive a reply from the server
        if( recv(sock , server_reply , 2000 , 0) < 0)
        {
            puts("recv failed");
            break;
        }
         
        puts("Server reply :");
        puts(server_reply);
    }
     
    close(sock);

}

/* Thread that controls the status of the client */
void stopClient(client *pClient){
	if(pClient->status){
		getchar();
		printf("\nClient stopped by user.\n");
		pClient->status = 0;
	}
	return NULL;
}

void startAutomaticClient(client *pClient){
	int id = 1;
	pClient->status = 1;
	pthread_t stopClientThread;
	int burst,priority,waiting = 0;
	pthread_create(&stopClientThread, NULL, stopClient, pClient);

	createSocket();

	printf("|%10s|%10s|%10s|%10s|\n","ID","Burst","Priority","Waiting");
	while(pClient->status){
		burst = getRandomNumber(1,MAX_BURST);
		priority = getRandomNumber(1,MAX_PRIORITY);
		waiting = getRandomNumber(1,MAX_WAIT);
		if(pClient->status){
			printf("|%10d|%10d|%10d|%10d|\n",id,burst,priority,waiting);
		}
		sleep(waiting);
		id++;
	}
	pthread_join(stopClientThread, NULL);
}

void startManualClient(client *pClient){
	pClient->status = 1;
	/* to-do */
}