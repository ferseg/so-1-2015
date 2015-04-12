#include "../Headers/cpuScheduler.h"
#include "pthread.h"
#include "../Headers/process.h"
#include "../Headers/jobScheduler.h"

#define PRINT 1

int main() {
	// TODO: Change by enq with process of the client side
	// 
	//if (pthread_mutex_init(&lock, NULL) != 0)
    //{
    //    printf("\n mutex init failed\n");
    //    return 1;
    //}
	queue *q = newQueue();
	int i;
	int j = 6;
	for (i = 0; i < 5; ++i)
	{
		process *np = newProcess(i, j-i, i);
		// jobScheduler.h
		insertProcess(q, np, ROUND_ROBIN);
	}
	int sizeofInt = sizeof(int);
	pthread_t *thread = malloc(sizeof(pthread_t));
	// Create CPU is called from cpuScheduler.h
	cpuScheduler_t *cpu = createCPU(q, ROUND_ROBIN);
	cpu->quantum = 2;
	pthread_create(&thread, NULL, initCPU, (void *) cpu);

	int selectedOption;
	// Menu
	do {
		printf("%s\n", "======= MENU =======");
		printf("%s\n", "1. Print Ready");
		printf("%s\n", "2. Exit");
		printf("%s", "Choose an option: ");
		scanf("%d", &selectedOption);
		while(selectedOption < 0 || selectedOption > 2) {
			printf("%s\n", "[!] Invalid option.");
			sleep(1);
			printf("%s", "Choose an option: ");
			scanf("%d", &selectedOption);
		}
		if (selectedOption == PRINT) {
			printQueue(cpu->ready);
		}
		else {
			cpu->running = STOPPED;
		}
	} while(cpu->running);

	pthread_join(thread, NULL);
	return 0;
}