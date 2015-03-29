#include "../Headers/queue.h"
 
int main()
{
	struct process *p1 = new_process(1,8,2);
	struct process *p2 = new_process(2,6,1);
	struct process *p3 = new_process(3,11,4);
	struct process *p4 = new_process(4,9,3);
	struct process *p5 = new_process(5,2,2);
	
	printf("-----------------Testing Queue-----------------\n");
	create();
	enq(p1);
	
//	display();
//	struct process *p = deq();
	
	printf("-----------------Testing Queue-----------------\n");
	enq(p2);
	enq(p3);
	enq(p4);
	enq(p5);
	display();
	
	return 0;
}
