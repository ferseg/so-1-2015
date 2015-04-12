#include "../Headers/cpuScheduler.h"
#include "pthread.h"
#include "../Headers/queue.h"
#include "../Headers/socket.h"
#include "../Headers/cpuScheduler.h" // CPU scheduler
#include "../Headers/jobScheduler.h" // To insert in the ready

#define PRINT 1

int main() {

	queue *nQueue = newQueue();
	cpuScheduler_t *cpu = createCPU(nQueue, FIFO);
	//initCPU(cpu);
    pthread_t queueManagerThread;
    pthread_create(&queueManagerThread, NULL, sendDataToQueue, (void*)cpu);
    
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

    sleep(20);
    pthread_join(queueManagerThread, NULL);
    printf("Se acabó el tiempo :(\n");

	/*queue *q = newQueue();
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


	pthread_join(thread, NULL);*/
	return 0;
}