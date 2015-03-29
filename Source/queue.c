<<<<<<< HEAD:Source/queue.c
#include "queue.h"

int count = 0;
 
=======
#ifndef QUEUE_H_   /* Include guard */
#define QUEUE_H_

struct queue
{
    struct process *current;
    struct queue *next;
}*front,*rear,*temp,*front1;

>>>>>>> ae621adb782fa6876515a7f64155a3abad298e84:src/queue.h
/* Create an empty queue */
void create();
 
/* Returns queue size */
void queuesize();
 
/* Enqueing the queue */
void enq(int pId,int pBurst,int pPriority);

/* Dequeing the queue */
<<<<<<< HEAD:Source/queue.c
void deq()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->next != NULL)
        {
            front1 = front1->next;
            printf("\nDequed value : %d\n\n", get_id(front->current));
            
            free(front);
            front = front1;
        }
        else
        {
            printf("\nDequed value : %d\n\n", get_id(front->current));
            
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}
=======
void deq();
>>>>>>> ae621adb782fa6876515a7f64155a3abad298e84:src/queue.h

/* Displaying the queue elements */
void display();

#endif // QUEUE_H_
