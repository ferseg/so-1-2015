#include "../Headers/queue.h"

/* Create an empty queue */
queue* newQueue()
{
	queue *newQueue = malloc(sizeof(queue));
	newQueue->count = 0;
	newQueue->front = NULL;
	newQueue->rear = NULL;
	return newQueue;
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
    	pQueue->front = malloc(sizeof(node));
        pQueue->rear = malloc(sizeof(node));
        pQueue->rear = newNode(pProcess);
        pQueue->front = pQueue->rear;
    }
    else
    {   
		node *nNode = newNode(pProcess);
        setNext(pQueue->rear, nNode);
        pQueue->rear = nNode;
        nNode->next = NULL;
    }
    pQueue->count++;
}

/* Dequeing the queue */
process* deq(queue *pQueue)
{
	node *firstNode = pQueue->front;
    if (firstNode == NULL)
    {
        pQueue->count = 0;
        return NULL;
    }
    process *proc = firstNode->current;
    if (firstNode->next != NULL)
    {
        pQueue->front = firstNode->next;
    }
    else
    {
        pQueue->front = NULL;
        pQueue->rear = NULL;
        free(pQueue->front);
    }
    firstNode->next = NULL;
    firstNode->before = NULL;
    pQueue->count -= 1;
    return proc;
}

/* Displaying the queue elements */
void printQueue(queue *pQueue)
{
    node *currentNode = pQueue->front;
 
    if ((currentNode == NULL) && (pQueue->rear == NULL))
    {
        printf("\n[!] Queue is empty %d\n\n", pQueue->count);
        return;
    }
    printf("------------- Queue Data ---------------\n");
    while (currentNode != NULL)
    {
        printData(currentNode);
        currentNode = currentNode->next;
    }
    /*if (currentNode == pQueue->rear)
        printData(currentNode);*/
    printf("------------- END OF DATA Size: %d-------------\n\n", pQueue->count);
}
