#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "process.h"

struct process* new_process(int pId, int pBurst,int pPriority) {
	struct process *p = (struct process*)malloc(sizeof(struct process));
  	p->id = pId;
  	p->burst = pBurst;
  	p->state = 0;
	p->priority = pPriority;
	return p;
}

int get_id(struct process *pProcess){
	return pProcess->id;
}

int get_burst(struct process *pProcess){
	return pProcess->burst;
}

int get_state(struct process *pProcess){
	return pProcess->state;
}

int get_priority(struct process *pProcess){
	return pProcess->priority;
}

void update_state(struct process *pProcess,int pValue){
	pProcess->state += pValue;
}

const char * to_string(struct process *pProcess)
{
	char *str;
	asprintf(&str, "ID value: %d\nBurst value: %d\nState: %d/%d\nPriority value: %d\n",
			pProcess->id,
			pProcess->burst,
			pProcess->state,
			pProcess->burst,
			pProcess->priority);
    return str;
}

void print_data(struct process *pProcess){
	printf("%s\n",to_string(pProcess));
}

