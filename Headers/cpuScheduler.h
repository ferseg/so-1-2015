/**
* Copyrigth © 2015, All rights reserved.
* observer.h
* Author: Fernando Segovia Salgado
*/
#include "queue.h"
#include "algorithms.h"
#include "fileManager.h"
#include <unistd.h>
#ifndef CPU_SCHEDULER_H_
#define CPU_SCHEDULER_H_

#define RUNNING 1
#define STOPPED 0
#define STOP_WHEN_QUEUE_IS_EMPTY 2
// The sleep for the mini burst
#define MINI_BURST_SLEEP 1
#define EXIT_WO_ERROR 0

// To write in the file
#define LOG_FILE "log_file.txt"
#define WRITE_OPTION "w"
#define APPEND_OPTION "a"
#define TIMING_FILE "timing.txt"

pthread_mutex_t lock;

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

process* getLowerP(cpuScheduler_t*);

void saveProcessEndingInfo(process* proc, FILE *file, float tat, float wt);\

int selectQuantum(process*, int);

#endif // CPU_SCHEDULER_H_