#include "../Headers/queue.h"
 
int main()
{
	printf("----------------Testing Process----------------\n");
	struct process *p1 = new_process(1,8,1);
	print_data(p1);
	update_state(p1,2);
	print_data(p1);
	printf("-----------------------------------------------\n");
	
	printf("-----------------Testing Queue-----------------\n");
	create();
	enq(1,8,2);
	enq(2,6,1);
	enq(3,11,4);
	enq(4,9,3);
	
	display();	
	queuesize();
	
	deq();
	display();	
	queuesize();
	
	return 0;
}
