#include "stdio.h"
#include "../Headers/process.h"

#ifndef NODE_H_   /* Include guard */
#define NODE_H_

typedef struct node
{
    process *current;
    struct node *next;
}node;

/* Create an empty node */
node* newNode(process *pProcess);

/* Sets pointer to next node */
void setNext(node *curNode,node *nextNode);

/* Prints the node information */
void printData(node *pNode);

#endif // NODE_H_
