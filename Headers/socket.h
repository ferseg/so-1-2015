#include <stdio.h>
#include <string.h>    //strlen
#include <stdlib.h>    //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write
#include <pthread.h> //for threading , link with lpthread

#ifndef SOCKET_H_   /* Include guard */
#define SOCKET_H_

/* Create a client */
int testConnection();

void sendDataToServer(char *message);

void getTokens(char *str,int *id,int *burst, int *priority);

void *connection_handler(void *socket_desc);

#endif // SOCKET_H_