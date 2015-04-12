/*
    C socket server example, handles multiple clients using threads
*/
#include <stdio.h>
#include <string.h>    //strlen
#include <stdlib.h>    //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write
#include <pthread.h> //for threading , link with lpthread
#include "..Headers/socket.h"

int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c , *new_sock;
    struct sockaddr_in server , client;
     
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
     
    //Bind
    bind(socket_desc,(struct sockaddr *)&server , sizeof(server));
    puts("bind done");
     
    //Listen
    listen(socket_desc , 3);
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    
    while( client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c) ){
        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;
        queue *newQueue = newQueue();
        if( pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) new_sock, newQueue) < 0)
        {
            perror("could not create thread");
            return 1;
        }
         
        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( sniffer_thread , NULL);
    }
    return 0;
}