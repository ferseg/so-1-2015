#include <time.h>

#ifndef TIMER_H_   /* Include guard */
#define TIMER_H_

typedef struct timer{
	clock_t *start;
	float stop;
}timer;

timer* newTimer();
void stopTimer(timer *pTimer);
float getTimer(timer *pTimer);

#endif // TIMER_H_
