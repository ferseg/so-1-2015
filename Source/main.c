#include "../Headers/queue.h"
 
int main()
{
	struct process *p1 = new_process(1,8,2);
	update_state(p1,2);
	
	printf("-----------------Testing Queue-----------------\n");
	create();
	enq(p1);
	
//	display();
//	struct process *p = deq();
	enq(new_process(2,6,1));
	enq(new_process(3,11,4));
	enq(new_process(4,9,3));
	enq(new_process(5,2,2));
	display_queue();
	
	return 0;
}
