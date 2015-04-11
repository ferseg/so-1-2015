#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Headers/timer.h"
#ifndef PROCESS_H_   /* Include guard */
#define PROCESS_H_

typedef struct process 
{
    int id;
    int priority;
    int burst;
    int state;
    int timesOnReady;
    struct timer *timer;
}process;

/* Create a process */
process* newProcess(int pId, int pBurst,int pPriority);

/* Gets the process id */
int getId(process *pProcess);

/* Gets the process burst */
int getBurst(process *pProcess);

/* Gets the process state */
int getState(process *pProcess);

/* Gets the process priority */
int getPriority(process *pProcess);

/* 1 if the process is over 0 if it does't */
int isOver(process *pProcess);

/* Updates the state of a process */
void updateState(process *pProcess,int pValue);

/* Gets the rest of the time that the process needs to finish */
int getNeededTime(process *pProcess);

/* Gets the process Waiting Time */
float getWT(process *pProcess);

/* Gets the process Turn-around Time */
float getTAT(process *pProcess);

/* Returns a string with information about the process */
const char * processToString(process *pProcess);

/* Prints the information of the process */
void printProcess(process *pProcess);

#endif // PROCESS_H_
