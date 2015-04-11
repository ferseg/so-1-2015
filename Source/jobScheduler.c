#include "../Headers/jobScheduler.h"

void listen(char *info) {
	// TODO: read the info from the socket
}

void insertProcess(queue *ready, process *proc, int algorithm) {
	node *actual = ready->front;	
	if(actual == NULL || algorithm == FIFO || algorithm == ROUND_ROBIN) {
		enq(ready, proc);
		return;
	}
	node *toInsert = newNode(proc);
	while(actual != NULL) {
		int actualValue;
		int lastValue;
		process *actualProcess = actual->current;
		switch (algorithm) {
			// For SJF the scheduler must search with burst criteria
			case SJF:
				actualValue = proc->burst;
				lastValue = actualProcess->burst;
				break;
			// For SJF the scheduler must search with priority criteria
			case HPF:
				actualValue = proc->priority;
				lastValue = actualProcess->priority;
				break;
		}
		if(isLower(actualValue, lastValue)) {
			toInsert->next = actual;
			toInsert->before = actual->before;
			actual->before = toInsert;
			if(actual == ready->front) {
				ready->front = toInsert;
			}
			ready->count++;
			return;
		}
		actual = actual->next;
	}
	ready->rear->next = toInsert;
	toInsert->before = ready->rear;
	ready->rear = toInsert;
	ready->count++;
	return;
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