#include "../Headers/socket.h"

int main(int argc , char *argv[])
{

    queue *nQueue = newQueue();
    sendDataToQueue(nQueue);

    //sendDataToQueue(nQueue);
    
    // int socket_desc , client_sock , c , read_size;
    // struct sockaddr_in server , client;
    
    // //Create socket
    // socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    // puts("Socket created");
     
    // //Prepare the sockaddr_in structure
    // server.sin_family = AF_INET;
    // server.sin_addr.s_addr = INADDR_ANY;
    // server.sin_port = htons( 8888 );
     
    // //Bind
    // bind(socket_desc,(struct sockaddr *)&server , sizeof(server));
    // puts("bind done");
     
    // //Listen
    // listen(socket_desc , 3);
     
    // //Accept and incoming connection
    // puts("Waiting for incoming connections...");
    // c = sizeof(struct sockaddr_in);
     
    // //accept connection from an incoming client
    // client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    // puts("Connection accepted");
    // //Receive a message from client
    // char client_message[2000];
    // while( client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c) ){
    //     recv(client_sock , client_message , 2000 , 0);
    //     if(strlen(client_message) == 1){
    //         //////////////////////////////////////////////////////////
    //         // algoritmo para ordenar
    //         printf("El algoritmo para ordenar es: %s\n",client_message);
    //         //////////////////////////////////////////////////////////
    //     }
    //     else{
    //         int id,burst,priority;
    //         getTokens(client_message,&id,&burst,&priority);
    //         //////////////////////////////////////////
    //         //aquí debería de insertar en la  cola////
    //         enq(nQueue,newProcess(id,burst,priority));
    //         printQueue(nQueue);
    //         //////////////////////////////////////////
    //     }
    // }
    return 0;
}