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
 * @param scheduler
 */
void* initCPU(void *scheduler) {
	cpuScheduler_t *cpuSch = (cpuScheduler_t *) scheduler;
	cpuSch->running = RUNNING;
	int quantum = cpuSch->quantum;
	while(cpuSch->running) {
		if(cpuSch->ready->count != EMPTY) {
			process *actual = deq(cpuSch->ready);//searchForProcess(cpuSch);
			// Chooses the burst to execute if the algorithm is RR
			// then it executes the quantum and updates its state
			int burst = cpuSch->algorithm == ROUND_ROBIN ? 
				selectQuantum(actual, quantum) : actual->burst;
			int miniBurst = EMPTY;
			while(miniBurst < burst) {
				sleep(MINI_BURST_SLEEP);
				miniBurst++;
			}
			// Updates the actual state
			actual->state += miniBurst;
			printProcess(actual);
			printf("burst: %d\n\n", burst);
			// The times on ready
			actual->timesOnReady++;
			if(cpuSch->algorithm == ROUND_ROBIN && actual->burst != actual->state) {
				enq(cpuSch->ready, actual);
			}
		}
	}
	// Sends a signal to tell that the thread has finished
	pthread_exit(EXIT_WO_ERROR);
}

/**
 * Selects the burst of the process evaluating its burst
 * if the left burst is lower than the quantum then returns the
 * left burst
 * @param  actual  The actual process
 * @param  quantum The quantum
 * @return         quantum if left burst is higher, left otherwise
 */
int selectQuantum(process *actual, int quantum) {
	int burst = actual->burst;
	int state = actual->state;
	int left = burst - state;
	if (left > quantum) {
		return quantum;
	}
	return left;
}

/*process* searchForProcess(cpuScheduler_t *scheduler) {
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
/*process* getLower(cpuScheduler_t *scheduler) {
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
	// Remove the node from the queue
	best->before->next = best->next;
	best->next->before = best->before;
	best->next, best->before = NULL;
	return best->current;
}*/
