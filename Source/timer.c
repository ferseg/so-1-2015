#include "../Headers/timer.h"

timer* newTimer(){
	timer *nt = malloc(sizeof(timer));
	time(&nt->start);
	nt->stop = NULL;
	return nt;
}

void stopTimer(timer *pTimer){
	if(pTimer->stop == NULL) {
		time(&pTimer->stop);
	}
}

float getTimer(timer *pTimer){
	stopTimer(pTimer);
	return difftime(pTimer->stop, pTimer->start);
}
