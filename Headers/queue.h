#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Headers/node.h"

#ifndef QUEUE_H_   /* Include guard */
#define QUEUE_H_

typedef struct queue 
{
    node *front;
    node *rear;
    int count;
}queue;

/* Create an empty queue */
queue* newQueue();
 
/* Returns queue size */
int getQueueSize();

/* Enqueing the queue */
void enq(queue *pQueue, process *pProcess);

/* Dequeing the queue */
process* deq(queue *pQueue);

/* Displaying the queue elements */
void printQueue(queue *pQueue);

#endif // QUEUE_H_
