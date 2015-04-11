#include "../Headers/client.h"

client* newClient(int pType, int pSortingMethod){
	client *nc = malloc(sizeof(client));
	nc->type = pType;
	nc->sortingMethod = pSortingMethod;
	nc->status = 0;
	return nc;
}

int getRandomNumber(int pMinNum, int pMaxNum){
    return (rand() % (pMaxNum - pMinNum + 1)) + pMinNum;
}

/* Thread that controls the status of the client */
void stopClient(client *pClient){
	if(pClient->status){
		getchar();
		printf("\nClient stopped by user.\n");
		pClient->status = 0;
	}
	return NULL;
}

void startAutomaticClient(client *pClient){
	int id = 1;
	pClient->status = 1;
	pthread_t stopClientThread;
	int burst,priority,waiting = 0;
	pthread_create(&stopClientThread, NULL, stopClient, pClient);
	printf("|%10s|%10s|%10s|%10s|\n","ID","Burst","Priority","Waiting");
	while(pClient->status){
		burst = getRandomNumber(1,MAX_BURST);
		priority = getRandomNumber(1,MAX_PRIORITY);
		waiting = getRandomNumber(1,MAX_WAIT);
		if(pClient->status){
			printf("|%10d|%10d|%10d|%10d|\n",id,burst,priority,waiting);
		}
		sleep(waiting);
		id++;
	}
	pthread_join(stopClientThread, NULL);
}

void startManualClient(client *pClient){
	pClient->status = 1;
	/* to-do */
}