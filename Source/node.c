#include "../Headers/node.h"

/* Create an empty queue */
node* newNode(process *pProcess){
    node *newNode = malloc(sizeof(node));
    newNode->current = pProcess;
    newNode->next = NULL;
    newNode->before = NULL;
    return newNode;
}

void setNext(node *curNode,node *nextNode){
	curNode->next = nextNode;
	nextNode->before = curNode;
}

void printData(node *pNode){
	printProcess(pNode->current);
}
