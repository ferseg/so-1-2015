#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Headers/timer.h"
#include "../Headers/process.h"


struct process* new_process(int pId, int pBurst,int pPriority) {
	struct process *p = (struct process*)malloc(sizeof(struct process));
  	p->id = pId;
  	p->burst = pBurst;
  	p->state = 0;
	p->priority = pPriority;
	p->timer = new_timer();
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
	if(pProcess->burst == pProcess->state){
		stop_timer(pProcess->timer);
	}
}

const char * to_string(struct process *pProcess)
{
	char *str;
	asprintf(&str, "ID: %d\nBurst: %d\nState: %d/%d\nPriority: %d\nWaiting Time: %f\n",
			pProcess->id,
			pProcess->burst,
			pProcess->state,
			pProcess->burst,
			pProcess->priority,
			get_timer(pProcess->timer));
    return str;
}

void print_data(struct process *pProcess){
	printf("%s\n",to_string(pProcess));
}

