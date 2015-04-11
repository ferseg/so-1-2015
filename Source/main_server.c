#include "../Headers/cpuScheduler.h"
#include "pthread.h"
#include "../Headers/process.h"

#define PRINT 1

int main() {
	// TODO: Change by enq with process of the client side
	queue *q = newQueue();
	int i;
	int j = 100;
	for (i = 0; i < 100; ++i)
	{
		process *np = newProcess(i, i, i);
		enq(q, np);
	}
	process *np = newProcess(2,3,5);
	int sizeofInt = sizeof(int);
	pthread_t *thread = malloc(sizeof(pthread_t));
	// Create CPU is called from cpuScheduler.h
	cpuScheduler_t *cpu = createCPU(q, 1);
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
	printProcess(getLower(cpu));
	return 0;
}