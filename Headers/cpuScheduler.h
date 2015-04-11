/**
* Copyrigth © 2015, All rights reserved.
* observer.h
* Author: Fernando Segovia Salgado
*/
#include "queue.h"
#include "algorithms.h"
#include <unistd.h>
#ifndef CPU_SCHEDULER_H_
#define CPU_SCHEDULER_H_

#define RUNNING 1
#define STOPPED 0
// The sleep for the mini burst
#define MINI_BURST_SLEEP 1
#define EXIT_WO_ERROR 0

typedef struct {
	unsigned short int algorithm;
	unsigned short int running;
	unsigned short int quantum;
	struct queue *ready;
} cpuScheduler_t;

/**
 * Creates a cpu scheduler instance
 * @param *ready the queue to be observed
 * @param algorithm the type of algorithm
 * @return the cpu scheduler instance
 */
cpuScheduler_t* createCPU(queue *ready, int algorithm);

/**
 * Initiates to observe the queue makes a new thread to observe it
 * @param observer the observer
 */
void* initCPU(void *scheduler);

void executeProcess(process* proc);

process* searchForProcess(cpuScheduler_t *scheduler);

process* getLower(cpuScheduler_t*);

int isLower(int, int);

int selectQuantum(process*, int);

#endif // CPU_SCHEDULER_H_