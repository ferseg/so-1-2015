#include "../Headers/node.h"

/* Create an empty queue */
node* newNode(process *pProcess){
    node *newNode = malloc(sizeof(node));
    newNode->current = pProcess;
    newNode->next = NULL;
    return newNode;
}

<<<<<<< HEAD
void setNext(node *curNode, node *nextNode){
=======
void setNext(node *curNode,node *nextNode){
>>>>>>> ken-dev
	curNode->next = nextNode;
}

void printData(node *pNode){
	printProcess(pNode->current);
}
