#include "../Headers/process.h"

process* newProcess(int pId, int pBurst,int pPriority) {
	process *newProcess = malloc(sizeof(process));
  	newProcess->id = pId;
  	newProcess->burst = pBurst;
  	newProcess->state = 0;
	newProcess->priority = pPriority;
	newProcess->timer = newTimer();
	return newProcess;
}

int getId(process *pProcess){
	return pProcess->id;
}

int getBurst(process *pProcess){
	return pProcess->burst;
}

int getState(process *pProcess){
	return pProcess->state;
}

int getPriority(process *pProcess){
	return pProcess->priority;
}

int isOver(process *pProcess){
	if(pProcess->burst == pProcess->state)
		return 1;
	return 0;
}

void updateState(process *pProcess,int pValue){
	pProcess->state += pValue;
	if(pProcess->burst == pProcess->state){
		stopTimer(pProcess->timer);
	}
}

int getNeededTime(process *pProcess){
	return pProcess->burst - pProcess->state;
}

float getWT(process *pProcess){
	return getTimer(pProcess->timer) - pProcess->burst;
}

float getTAT(process *pProcess){
	return getTimer(pProcess->timer);
}

const char * processToString(process *pProcess){
	char *str;
	asprintf(&str, "ID: %d\nBurst: %d\nState: %d/%d\nPriority: %d\n",
			pProcess->id,
			pProcess->burst,
			pProcess->state,
			pProcess->burst,
			pProcess->priority);
    return str;
}

void printProcess(process *pProcess){
	printf("%s\n",processToString(pProcess));
}
<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> master
=======

>>>>>>> ken-dev
