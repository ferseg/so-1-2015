#include "../Headers/timer.h"

struct timer* new_timer(){
	struct timer *nt = (struct timer*)malloc(sizeof(struct timer));
	nt->start = clock();
	nt->stop = -1;
	return nt;
}

void stop_timer(struct timer *pTimer){
	pTimer->stop = (float)(clock() - (clock_t)pTimer->start) / CLOCKS_PER_SEC;
}

float get_timer(struct timer *pTimer){
	float msec;
	if(pTimer->stop >= 0){
		msec = pTimer->stop;
	}
	else{
		msec = (float)(clock() - (clock_t)pTimer->start) / CLOCKS_PER_SEC;	
	}
	return msec;
}

