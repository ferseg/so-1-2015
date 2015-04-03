#include "../Headers/node.h"

/* Create an empty queue */
node* newNode(process *pProcess){
    node *newNode = malloc(sizeof(node));
    newNode->current = pProcess;
    newNode->next = NULL;
    return newNode;
}

void setNext(node *curNode, node *nextNode){
	curNode->next = nextNode;
}

void printData(node *pNode){
	printProcess(pNode->current);
}
