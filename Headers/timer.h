#include <time.h>

#ifndef TIMER_H_   /* Include guard */
#define TIMER_H_

typedef struct timer{
	time_t start;
	time_t stop;
}timer;

timer* newTimer();
void stopTimer(timer *pTimer);
float getTimer(timer *pTimer);

#endif // TIMER_H_
