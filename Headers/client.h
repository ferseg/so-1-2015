#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <string.h>    //strlen
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr

#ifndef CLIENT_H_   /* Include guard */
#define CLIENT_H_

#define MAX_WAIT 5
#define MAX_BURST 20
#define MAX_PRIORITY 5
//#define CLIENT_MENU "Seleccione un tipo de cliente\n1-Manual\n2-Automático\n3-Salir\n"


typedef struct client
{
    int type;
    int sortingMethod;
    int status;
}client;

/* Create a client */
client* newClient(int pType, int pAlgorithm);

void startClient();

void startAutomaticClient(client *pClient);

void startManualClient(client *pClient);

#endif // CLIENT_H_
