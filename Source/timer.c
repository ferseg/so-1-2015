#include <stdlib.h>
#include "../Headers/timer.h"

struct timer* new_timer(){
	struct timer *nt = (struct timer*)malloc(sizeof(struct timer));
	nt->start = clock();
	nt->stop = -1;
	return nt;
}

void stop_timer(struct timer *pTimer){
	pTimer->stop = clock() - (clock_t)pTimer->start;
}

clock_t get_start(struct timer *pTimer){
	return pTimer->start;
}

float get_stop(struct timer *pTimer){
	return pTimer->stop;
}

void get_timer(struct timer *pTimer){
	int msec;
	if(pTimer->stop >= 0){
		msec = pTimer->stop * 1000 / CLOCKS_PER_SEC;
		printf("\nTime taken %d seconds %d milliseconds", msec/1000, msec%1000);
		return;
	}
	clock_t diff;	
	diff = clock() - (clock_t)pTimer->start;
	msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("\nasdTime taken %d seconds %d milliseconds", msec/1000, msec%1000);

}

void print_timer(struct timer *pTimer){
	if(pTimer->stop != 0){
		int msec = pTimer->stop * 1000 / CLOCKS_PER_SEC;
		printf("\nTime taken %d seconds %d milliseconds", msec/1000, msec%1000);
		return;
	}
	clock_t diff;
	diff = clock() - (clock_t)pTimer->start;
	int msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("\nTime taken %d seconds %d milliseconds", msec/1000, msec%1000);
}
