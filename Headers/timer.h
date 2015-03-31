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
float get_timer(struct timer *pTimer);
float test_float();

#endif // TIMER_H_
