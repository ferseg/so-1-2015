#include "../Headers/client.h"
#include "../Headers/queue.h"

int main()
{
//	struct client *c1 = new_client(1,0);
//	printf("%d\n%d\n%d\n",get_type(c1),get_sorting_method(c1),get_status(c1));

	queue *q = newQueue();
	enq(q,newProcess(1,8,2));
	enq(q,newProcess(2,6,3));
	printQueue(q);
	process *p1 = deq(q);
	printQueue(q);
	
	
	updateState(p1,8);
	printProcess(p1);
	
	
	


	
	return 0;
}
