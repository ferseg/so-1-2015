#include "../Headers/queue.h"

/* Create an empty queue */
queue* newQueue()
{
<<<<<<< HEAD
    queue *newQueue = malloc(sizeof(queue));
    newQueue->count = 0;
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
=======
	queue *newQueue = malloc(sizeof(queue));
	newQueue->count = 0;
	newQueue->front = NULL;
	newQueue->rear = NULL;
	return newQueue;
>>>>>>> master
}
 
/* Returns queue size */
int getQueueSize(queue *pQueue)
{
    return pQueue->count;
}

/* Enqueing the queue */
void enq(queue *pQueue, process *pProcess)
{
    if (pQueue->rear == NULL)
    {
<<<<<<< HEAD
        pQueue->front = malloc(sizeof(node));
=======
    	pQueue->front = malloc(sizeof(node));
>>>>>>> master
        pQueue->rear = malloc(sizeof(node));
        pQueue->rear = newNode(pProcess);
        pQueue->front = pQueue->rear;
    }
    else
    {   
<<<<<<< HEAD
        node *nNode = newNode(pProcess);
=======
		node *nNode = newNode(pProcess);
>>>>>>> master
        setNext(pQueue->rear, nNode);
        pQueue->rear = nNode;
    }
    pQueue->count++;
}

/* Dequeing the queue */
process* deq(queue *pQueue)
{
<<<<<<< HEAD
    process *firstProcess;
    node *newFront = pQueue->front;
=======
	process *firstProcess;
	node *newFront = pQueue->front;
>>>>>>> master
    if (newFront == NULL)
    {
        return firstProcess;
    }
    else
        if (newFront->next != NULL)
        {
            newFront = newFront->next;
<<<<<<< HEAD
            firstProcess = pQueue->front->current;
=======
  			firstProcess = pQueue->front->current;
>>>>>>> master
            free(pQueue->front);
            pQueue->front = newFront;
        }
        else
        {
<<<<<<< HEAD
            firstProcess = pQueue->front->current;
=======
    		firstProcess = pQueue->front->current;
>>>>>>> master
            free(pQueue->front);
            pQueue->front = NULL;
            pQueue->rear = NULL;
        }
        pQueue->count--;
        return firstProcess;
}

/* Displaying the queue elements */
void printQueue(queue *pQueue)
{
    node *currentNode = pQueue->front;
 
    if ((currentNode == NULL) && (pQueue->rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (currentNode != pQueue->rear)
    {
        printData(currentNode);
        currentNode = currentNode->next;
    }
    if (currentNode == pQueue->rear)
        printData(currentNode);
    printf("\n-------------Queue size : %d-------------", getQueueSize(pQueue));
}
