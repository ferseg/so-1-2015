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
	while(cpuSch->running) {
		process *actual = searchForProcess(cpuSch);
		printProcess(actual);
		sleep(actual->burst);
		if(cpuSch->ready->count == 0) {
			cpuSch->running = STOPPED;
		}
	}
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
