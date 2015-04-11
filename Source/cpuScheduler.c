/**
* Copyrigth © 2015, All rights reserved.
* cpuScheduler.c
* Author: Fernando Segovia Salgado
*/
#include "../Headers/cpuScheduler.h"

/**
 * Creates a new CPUScheduler that contains the ready queue and 
 * the algorithm of selection
 * @param  ready     Queue of processes
 * @param  algorithm The algorithm to select the best process
 * @return           A CPUScheduler
 */
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
		// Chooses the burst to execute if the algorithm is RR
		// then it executes the quantum and updates its state
		int burst = actual->burst;
		if (cpuSch->algorithm == ROUND_ROBIN) {
			// TODO with quantum burst = quantum
		}
		int miniBurst = EMPTY;
		while(miniBurst++ < burst) {
			sleep(MINI_BURST_SLEEP);
		}
		// Updates the actual state
		actual->state += miniBurst;
		// TODO: Enq if RR
		if(cpuSch->ready->count == EMPTY) {
			cpuSch->running = STOPPED;
		}
	}
	// Sends a signal to tell that the thread has finished
	pthread_exit(EXIT_WO_ERROR);
}


process* searchForProcess(cpuScheduler_t *scheduler) {
	queue *ready = scheduler->ready;
	process* best;
	switch(scheduler->algorithm) {
		// For FIFO AND RR the algorithm is a simple dequeue
		case FIFO:
		case ROUND_ROBIN:
			best = deq(ready);
			break;
		// SJF and HPF has the same algorithm to select the
		// proccess to be executed.
		case SJF:
		case HPF:
			best = getLower(scheduler);
			break;
	}
	return best;
}

/**
 * Gets the process with the lower measure depending on the algorithm
 * @param  scheduler The scheduler that has the ready on it
 * @return           The lowest process depending on the algorithm
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
			int actualValue;
			int lastValue;
			process *actualProcess = actual->current;
			switch (algorithm) {
				// For SJF the scheduler must search with burst criteria
				case SJF:
					actualValue = actualProcess->burst;
					lastValue = best->current->burst;
					break;
				// For SJF the scheduler must search with priority criteria
				case HPF:
					actualValue = actualProcess->priority;
					lastValue = best->current->priority;
					break;
			}
			// Changes if its 
			if(isLower(actualValue, lastValue)) {
				best = actual;
			}
		}
		else {
			// Remove the node from the queue
			best->before->next = best->next;
			best->next->before = best->before;
			best->next, best->before = NULL;
			return best->current;
		}
		actual = actual->next;
	}
	return best->current;
	// TODO: Sets the before and the next.
}

/**
 * Returns if a number is lower than other
 * @param  actualValue The first number
 * @param  lastValue The second number
 * @return TRUE if actualValue is lower than lastValue, FALSE otherwise
 */
int isLower(int actualValue, int lastValue) {
	return actualValue < lastValue;
}
