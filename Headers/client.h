#include <stdio.h>
#include <stdlib.h>
#ifndef CLIENT_H_   /* Include guard */
#define CLIENT_H_

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

#endif // CLIENT_H_
