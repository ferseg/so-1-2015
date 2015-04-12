#include "../Headers/socket.h"

int main(int argc , char *argv[])
{

    queue *nQueue = newQueue();
    pthread_t queueManagerThread;
    pthread_create(&queueManagerThread, NULL, sendDataToQueue, nQueue);
    //sendDataToQueue(nQueue);
    sleep(20);
    pthread_join(&queueManagerThread, NULL);
    printf("Se acabó el tiempo :(\n");
    return 0;
}