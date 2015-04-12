#include "../Headers/client.h"
#include "../Headers/queue.h"

int main()
{
	client *c1 = newClient(1,0);
	startAutomaticClient(c1);
	stopClient(c1);
	
	
	
	// queue *q = newQueue();
	// enq(q,newProcess(1,8,2));
	// enq(q,newProcess(2,6,3));
	// //printQueue(q);
	// process *p1 = deq(q);
	// //printQueue(q);
	
	// updateState(p1,8);
	// enq(q,p1);

	// int i = 0;
	// while(i<1000000000){
	// 	i++;
	// }
	// //printProcess(p1);
	// printQueue(q);
	// printf("%f\n",getTimer(p1->timer));
	// printf("%f\n",getTimer(q->front->current->timer));


	return 0;
}
