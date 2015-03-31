#include <stdio.h>
#include <stdlib.h>
#ifndef CLIENT_H_   /* Include guard */
#define CLIENT_H_

struct client
{
    int type;
    int sorting_method;
    int status;
};

/* Create a client */
struct client* new_client(int pType, int pAlgorithm);

/* Gets the client type */
int get_type(struct client *pClient);

/* Gets the client sorting_method */
int get_sorting_method(struct client *pClient);

/* Gets the client status */
int get_status(struct client *pClient);

#endif // CLIENT_H_
