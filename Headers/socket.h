#include <stdio.h> 
#include <string.h>    //strlen
#include <stdlib.h>    //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write
#include <pthread.h> //for threading , link with lpthread
#include "../Headers/queue.h"
#include "../Headers/process.h"
#include "../Headers/cpuScheduler.h" // CPU scheduler
#include "../Headers/jobScheduler.h" // To insert in the ready
#include "../Headers/algorithms.h"

#ifndef SOCKET_H_   /* Include guard */
#define SOCKET_H_

#define MESSAGE_LEN 2000


/* Create a client */
int testConnection();

void sendDataToServer(char *message);

void *sendDataToQueue(void *cpuSch);

void getTokens(char *str,int *id,int *burst, int *priority);

#endif // SOCKET_H_