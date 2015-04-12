#include "../Headers/socket.h"

int main(int argc , char *argv[])
{

    queue *nQueue = newQueue();
    sendDataToQueue(nQueue);

    return 0;
}