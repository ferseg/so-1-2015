#include "../Headers/timer.h"

timer* newTimer(){
	timer *nt = malloc(sizeof(timer));
	nt->start = clock();
	nt->stop = -1;
	return nt;
}

void stopTimer(timer *pTimer){
	pTimer->stop = (float)(clock() - (clock_t)pTimer->start) / CLOCKS_PER_SEC;
}

float getTimer(timer *pTimer){
	float msec;
	if(pTimer->stop >= 0){
		msec = pTimer->stop;
	}
	else{
		msec = (float)(clock() - (clock_t)pTimer->start) / CLOCKS_PER_SEC;	
	}
	return msec;
}
<<<<<<< HEAD
=======

>>>>>>> ken-dev
