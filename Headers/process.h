#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Headers/timer.h"
#ifndef PROCESS_H_   /* Include guard */
#define PROCESS_H_

struct process 
{
    int id;
    int burst;
    int state;
    int priority;
    struct timer *timer;
};

/* Create a process */
struct process* new_process(int pId, int pBurst,int pPriority);

/* Gets the process id */
int get_id(struct process *pProcess);

/* Gets the process burst */
int get_burst(struct process *pProcess);

/* Gets the process state */
int get_state(struct process *pProcess);

/* Gets the process priority */
int get_priority(struct process *pProcess);

/* 1 if the process is over 0 if it does't */
int isOver(struct process *pProcess);

/* Updates the state of a process */
void update_state(struct process *pProcess,int pValue);

/* Gets the rest of the time that the process needs to finish */
int get_needed_time(struct process *pProcess);

/* Gets the process Waiting Time */
float get_WT(struct process *pProcess);

/* Gets the process Turn-around Time */
float get_TAT(struct process *pProcess);

/* Returns a string with information about the process */
const char * to_string(struct process *pProcess);

/* Prints the information of the process */
void print_data(struct process *pProcess);

#endif // PROCESS_H_
