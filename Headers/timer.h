#include <time.h>
#include <stdlib.h>

#ifndef TIMER_H_   /* Include guard */
#define TIMER_H_

struct timer{
	clock_t *start;
	float stop;
};

struct timer* new_timer();
void stop_timer(struct timer *pTimer);
float get_timer(struct timer *pTimer);

#endif // TIMER_H_
