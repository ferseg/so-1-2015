#include <stdio.h>
#include <string.h>    //strlen
#include <stdlib.h>    //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write
#include <pthread.h> //for threading , link with lpthread
#include "../Headers/queue.h"

#ifndef SOCKET_H_   /* Include guard */
#define SOCKET_H_

typedef struct handlerArgs{
	queue *pQueue;
	void *socket_desc;
}handlerArgs;

handlerArgs* newArgs(void *socket_des,queue *pQueue);

/* Create a client */
int testConnection();

void sendDataToServer(char *message);

void getTokens(char *str,int *id,int *burst, int *priority);

void *connection_handler(handlerArgs *pArgs);

#endif // SOCKET_H_