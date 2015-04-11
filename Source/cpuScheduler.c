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
	int sumBurst = EMPTY;
	int totalProcess = EMPTY;
	float totalTAT;
	float totalWT;
	queue *tmpReady = newQueue();
	// Opens a file "fileManager.h"
	FILE *timingFile = openFile(TIMING_FILE, LOG_FILE_OPTIONS);
	writeInFile(timingFile, "Proceso \t|\tTAT \t|\tWT");
	while(cpuSch->running) {
		if(cpuSch->ready->count != EMPTY) {
			process *actual = deq(cpuSch->ready);

			/*sprintf(detail, "Proceso: %d con burst: %d y prioridad: %d entra en ejecucion\n", 
						actual->id, actual->burst, actual->priority);
			// Writes in the log file "fileManager.h"
			writeInFile(timingFile, detail);*/
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
			int actualBurst = actual->burst;
			if(actualBurst == actual->state) {
				float tat = getTAT(actual);
				float wt = tat - actualBurst;
				totalTAT += tat;
				totalWT += wt;
				printf("total wt: %.2f\n", totalWT);
				totalProcess++;
				sumBurst += actualBurst;
				saveProcessEndingInfo(actual, timingFile, tat, wt);
			}
			else if(cpuSch->algorithm == ROUND_ROBIN) {
				enq(tmpReady, actual);
			}
		}
		else {
			cpuSch->ready = tmpReady;
		}
	}
	float avgTAT = totalTAT / totalProcess;
	float avgWT = totalWT / totalProcess;
	char *detail = malloc(sizeof(char)*100);
	sprintf(detail, "Total: %d \t|\t%.2f \t|\t%.2f", totalProcess, avgTAT, avgWT);
	writeInFile(timingFile, "------------------------------------------------");
	writeInFile(timingFile, detail);
	// Closes the file "fileManager.h"
	closeFile(timingFile);
	// Sends a signal to tell that the thread has finished
	pthread_exit(EXIT_WO_ERROR);
}

/**
 * Saves the information of a process when it ends its execution
 * @param proc The process that will be saved
 * @param file The file in which the information will be saved
 * @param tat  Turn Around Time
 * @param wt   Wating Time
 */
void saveProcessEndingInfo(process *proc, FILE *file, float tat, float wt) {
	char *detail = malloc(sizeof(char)*700);
	sprintf(detail, "Proc: %d \t|\t%.0f \t|\t%.0f", proc->id, tat, wt);
	writeInFile(file, detail);
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
