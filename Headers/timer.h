#include <time.h>

#ifndef TIMER_H_   /* Include guard */
#define TIMER_H_

struct timer{
	clock_t *start;
	float stop;
};

struct timer* new_timer();
void stop_timer(struct timer *pTimer);
clock_t get_start(struct timer *pTimer);
float get_stop(struct timer *pTimer);
void get_timer(struct timer *pTimer);
void print_timer(struct timer *pTimer);

#endif // TIMER_H_
