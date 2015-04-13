/**
* Copyrigth © 2015, All rights reserved.
* jobScheduler.h
* Author: Fernando Segovia Salgado
*/
#include "queue.h"
#include "algorithms.h"
#ifndef JOB_SCHEDULER_H_
#define JOB_SCHEDULER_H_

void insertProcess(queue *ready, process *proc, int algorithm);
int isLower(int actual, int last);

#endif // JOB_SCHEDULER_H_