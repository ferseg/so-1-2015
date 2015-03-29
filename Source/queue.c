#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Headers/queue.h"

int count = 0;
struct queue *temp,*front1 = NULL;

/* Create an empty queue */
void create()
{
    front = rear = NULL;
}
 
/* Returns queue size */
int queuesize()
{
    return count;
}

/* Enqueing the queue */
void enq(struct process *pProcess)
{
    if (rear == NULL)
    {
    	front = (struct queue *)malloc(sizeof(struct queue));
        rear = (struct queue *)malloc(sizeof(struct queue));
        rear->next = NULL;
        rear->current = pProcess;
//        rear->current = new_process(pId,pBurst,pPriority);
        front = rear;
    }
    else
    {
        temp=(struct queue *)malloc(sizeof(struct queue));
        temp->next = NULL;
        rear->next = temp;
        temp->current = pProcess;
//        temp->current = new_process(pId,pBurst,pPriority);
        rear = temp;
    }
    count++;
}

/* Dequeing the queue */
struct process* deq()
{
    front1 = front;
    struct process *temp1;
    if (front1 == NULL)
    {
        return temp1;
    }
    else
        if (front1->next != NULL)
        {
            front1 = front1->next;
  			temp1 = front->current;
            free(front);
            front = front1;
        }
        else
        {
    		temp1 = front->current;
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
        return temp1;
}

/* Displaying the queue elements */
void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        print_data(front1->current);
        front1 = front1->next;
    }
    if (front1 == rear)
        print_data(front1->current);
    printf("\n-------------Queue size : %d-------------", queuesize());
}
