#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#ifndef CLIENT_H_   /* Include guard */
#define CLIENT_H_

#define MAX_WAIT 5
#define MAX_BURST 20
#define MAX_PRIORITY 5

typedef struct client
{
    int type;
    int sortingMethod;
    int status;
}client;

/* Create a client */
client* newClient(int pType, int pAlgorithm);

/* Gets the client type */
int getType(client *pClient);

/* Gets the client sorting_method */
int getSortingMethod(client *pClient);

/* Gets the client status */
int getStatus(client *pClient);

void startAutomaticClient(client *pClient);

void startManualClient(client *pClient);

void stopClient(client *pClient);

#endif // CLIENT_H_
