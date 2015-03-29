#include "queue.h"

int count = 0;
 
/* Create an empty queue */
void create()
{
    front = rear = NULL;
}
 
/* Returns queue size */
void queuesize()
{
    printf("\n-------------Queue size : %d-------------", count);
}
 
/* Enqueing the queue */
void enq(int pId,int pBurst,int pPriority)
{
    if (rear == NULL)
    {
        front = (struct queue *)malloc(sizeof(struct queue));
        rear = (struct queue *)malloc(sizeof(struct queue));
        rear->next = NULL;
        rear->current = new_process(pId,pBurst,pPriority);
        front = rear;
    }
    else
    {
        temp=(struct queue *)malloc(sizeof(struct queue));
        temp->next = NULL;
        rear->next = temp;
        temp->current = new_process(pId,pBurst,pPriority);
        rear = temp;
    }
    count++;
}

/* Dequeing the queue */
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
}