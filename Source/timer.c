#include <stdlib.h>
#include "../Headers/timer.h"

struct timer* new_timer(){
	struct timer *nt = (struct timer*)malloc(sizeof(struct timer));
	nt->start = (clock_t*)malloc(sizeof(clock_t));
	nt->start = clock();
	nt->stop = (clock_t*)malloc(sizeof(clock_t));
	nt->stop = NULL;
	return nt;
}

void stop_timer(struct timer *pTimer){
	pTimer->stop = (clock_t*)(clock() - (clock_t)pTimer->start);
}

clock_t get_start(struct timer *pTimer){
	return pTimer->start;
}

clock_t get_stop(struct timer *pTimer){
	return pTimer->stop;
}

void get_timer(struct timer *pTimer){
	if(pTimer->stop != NULL){
		int msec = (clock_t)(pTimer->stop) * 1000 / CLOCKS_PER_SEC;
		printf("\nTime taken %d seconds %d milliseconds", msec/1000, msec%1000);
		return;
	}
	clock_t diff;	
	diff = clock() - (clock_t)pTimer->start;
	int msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("\nTime taken %d seconds %d milliseconds", msec/1000, msec%1000);

}

void print_timer(struct timer *pTimer){
	if(pTimer->stop != NULL){
		int msec = (clock_t)(pTimer->stop) * 1000 / CLOCKS_PER_SEC;
		printf("\nTime taken %d seconds %d milliseconds", msec/1000, msec%1000);
		return;
	}
	clock_t diff;	
	diff = clock() - (clock_t)pTimer->start;
	int msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("\nTime taken %d seconds %d milliseconds", msec/1000, msec%1000);
}
