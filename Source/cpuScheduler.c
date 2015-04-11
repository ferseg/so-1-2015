/**
* Copyrigth © 2015, All rights reserved.
* cpuScheduler.c
* Author: Fernando Segovia Salgado
*/
#include "../Headers/cpuScheduler.h"

cpuScheduler_t* createCPU(queue *ready, int algorithm) {
	cpuScheduler_t *scheduler = malloc(sizeof(cpuScheduler_t));
	scheduler->ready = ready;
	scheduler->algorithm = algorithm;
	return scheduler;
}

/**
 * Inititates to execute the cpu scheduler
 * @param the sc
 */
void* initCPU(void *scheduler) {
	cpuScheduler_t *cpuSch = (cpuScheduler_t *) scheduler;
	cpuSch->running = RUNNING;
	//while(cpuSch->running) {
		process *actual = searchForProcess(cpuSch);
		//printProcess(actual);
		//sleep(actual->burst);
	//	if(cpuSch->ready->count == 0) {
	//		cpuSch->running = STOPPED;
	//	}
	//}
	pthread_exit(0);
}

process* searchForProcess(cpuScheduler_t *scheduler) {
	queue *ready = scheduler->ready;
	process* best;
	switch(scheduler->algorithm) {
		case FIFO:
			best = deq(ready);
			break;
		case SJF:
			best = deq(ready);
			break;
		case HPF:
			best = deq(ready);
			break;
		case ROUND_ROBIN:
			best = deq(ready);
			break;
	}
	return best;
}

/**
 * Gets the process with the lower measure depending on the algorithm
 * @param  scheduler [description]
 * @return           [description]
 */
process* getLower(cpuScheduler_t *scheduler) {
	queue *ready = scheduler->ready;
	// The best is the first node initially
	node *best = ready->front;
	node *actual = best->next;
	int algorithm = scheduler->algorithm;
	int i = 1;
	while(i++ < ready->count) {
		if(actual != NULL) {
			int a;
			int b;
			process *actualProcess = actual->current;
			switch (algorithm) {
				case SJF:
					a = actualProcess->burst;
					b = best->burst;
					break;
				case HPF:
					a = actualProcess->priority;
					b = best->priority;
					break;
			}
			if(isLower(a, b)) {
				actualProcess = best;
			}
		}
		else {
			return best->current;
		}
	}
	return best->current;
	// TODO: Sets the before and the next.
}

/**
 * Returns if a number is lower than other
 * @param  a The first number
 * @param  b The second number
 * @return TRUE if a is lower than b, FALSE otherwise
 */
int isLower(int a, int b) {
	return a < b;
}
