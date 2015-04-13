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
	scheduler->running = RUNNING;
	return scheduler;
}

/**
 * Inititates to execute the cpu scheduler
 * @param scheduler
 */
void* initCPU(void *scheduler) {
	cpuScheduler_t *cpuSch = (cpuScheduler_t *) scheduler;
	int quantum = cpuSch->quantum;
	int sumBurst = EMPTY;
	int totalProcess = EMPTY;
	float totalTAT;
	float totalWT;
	// Creates a timer to control idle CPU "timer.h"
	timer *idle = newTimer();
	// Opens a file "fileManager.h"
	FILE *timingFile = openFile(TIMING_FILE, WRITE_OPTION);
	writeInFile(timingFile, "Proceso \t|\tTAT \t|\tWT");
	while(cpuSch->running) {
		if(cpuSch->ready->count && (cpuSch->ready->front != NULL)) {
			//pthread_mutex_lock(&lock);
			process *actual = deq(cpuSch->ready);//searchForProcess(cpuSch);
			//deq(cpuSch->ready);
			//pthread_mutex_unlock(&lock);
			printf("\nProceso: %d con burst: %d y prioridad: %d entra en ejecucion.", 
						actual->id, actual->burst, actual->priority);

			puts("\n[->] Seleccione una opción [1, 2]: ");
			// Chooses the burst to execute if the algorithm is RR
			// then it executes the quantum and updates its state
			int burst = cpuSch->algorithm == ROUND_ROBIN ? 
				selectQuantum(actual, quantum) : actual->burst;
			int miniBurst = EMPTY;
			while(miniBurst < burst && cpuSch->running) {
				sleep(MINI_BURST_SLEEP);
				miniBurst++;
			}
			// Updates the actual state
			actual->state += miniBurst;
			int actualBurst = actual->burst;
			if(actualBurst == actual->state) {
				float tat = getTimer(actual->timer);
				float wt = tat - actualBurst;
				totalTAT += tat;
				totalWT += wt;
				totalProcess++;
				sumBurst += actualBurst;
				saveProcessEndingInfo(actual, timingFile, tat, wt);
			}
			else if(cpuSch->algorithm == ROUND_ROBIN) {
				//pthread_mutex_lock(&lock);
				enq(cpuSch->ready, actual);
				//pthread_mutex_unlock(&lock);
			}
		}
		else if (cpuSch->running == STOP_WHEN_QUEUE_IS_EMPTY) {
			cpuSch->running = STOPPED;
		}
	}
	float avgTAT = totalTAT / totalProcess;
	float avgWT = totalWT / totalProcess;
	char *detail = malloc(sizeof(char)*200);
	sprintf(detail, "Total: %d \t|\t%.2f \t|\t%.2f\n", totalProcess, avgTAT, avgWT);
	writeInFile(timingFile, "------------------------------------------------");
	writeInFile(timingFile, detail);
	float totalTime = getTimer(idle);
	float idleTime = totalTime - sumBurst;
	sprintf(detail, "CPU Ocioso: %0.2f", idleTime);
	writeInFile(timingFile, detail);
	// Closes the file "fileManager.h"
	closeFile(timingFile);
	// Sends a signal to tell that the thread has finished
	puts("Finalizó");
	pthread_exit(EXIT_WO_ERROR);
}

/**
 * Saves the information of a process when it ends its executions
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
			best = getLowerP(scheduler);
			break;
	}
	return best;
}*/

/**
 * Gets the process with the lower measure depending on the algorithm
 * @param  scheduler The scheduler that has the ready on it
 * @return           The lowest process depending on the algorithm
 */
/*process* getLowerP(cpuScheduler_t *scheduler) {
	puts("LoweP");
	queue *ready = scheduler->ready;
	// The best is the first node initially
	node *best = ready->front;
	node *actual = best;
	int algorithm = scheduler->algorithm;
	int i = 0;
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
			if(actualValue < lastValue) {
				best = actual;
			}
		}
		else {
			puts("Selected");
			// Remove the node from the queue
			if(best->before != NULL) {
				best->before->next = best->next;
			}
			if(best->next != NULL) {
				best->next->before = best->before;
			}
			best->next, best->before = NULL;
			ready->count--;
			return best->current;
		}
		actual = actual->next;
	}
	// Remove the node from the queue
	if(best->before != NULL) {
		best->before->next = best->next;
	}
	if(best->next != NULL) {
		best->next->before = best->before;
	}
	ready->count--;
	best->next, best->before = NULL;
	return best->current;
}*/
