#include "../Headers/queue.h"
#include "../Headers/timer.h"


int main()
{
	struct timer *t1 = new_timer();
	struct timer *t2 = new_timer();
	
	printf("-----------------Testing Queue-----------------\n");
	create();

	enq(new_process(1,8,2));
	enq(new_process(2,6,1));
	enq(new_process(3,11,4));
	enq(new_process(4,9,3));
	enq(new_process(5,2,2));
	display_queue();
	
	struct process *p = deq();
	update_state(p,2);
	enq(p);
	display_queue();
	
//	int i = 0;
//	while(i<100000000){
//		i++;
//	}i = 0;
//	
//	stop_timer(t1);
//
//	while(i<100000000){
//		i++;
//	}i = 0;
//	
//	printf("\nTime taken %f seconds", get_timer(t1));
//	printf("\nTime taken %f seconds", get_timer(t2));
	return 0;
}
