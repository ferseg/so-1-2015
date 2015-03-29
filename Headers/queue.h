#ifndef QUEUE_H_   /* Include guard */
#define QUEUE_H_

##include "process.h"

struct queue
{
    struct process *current;
    struct queue *next;
}*front,*rear,*temp,*front1;

/* Create an empty queue */
void create();
 
/* Returns queue size */
void queuesize();
 
/* Enqueing the queue */
void enq(int pId,int pBurst,int pPriority);

/* Dequeing the queue */
void deq();

/* Displaying the queue elements */
void display();

#endif // QUEUE_H_
