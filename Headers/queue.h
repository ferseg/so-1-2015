#ifndef QUEUE_H_   /* Include guard */
#define QUEUE_H_

struct queue
{
    struct process *current;
    struct queue *next;
}*front,*rear;

/* Create an empty queue */
void create();
 
/* Returns queue size */
int queuesize();
 

/* Enqueing the queue */
void enq(struct process *pProcess);

/* Dequeing the queue */
struct process* deq();

/* Displaying the queue elements */
void display_queue();

#endif // QUEUE_H_
