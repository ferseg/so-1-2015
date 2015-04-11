#include "../Headers/client.h"

client* newClient(int pType, int pSortingMethod){
	client *nc = malloc(sizeof(client));
	nc->type = pType;
	nc->sortingMethod = pSortingMethod;
	nc->status = 0;
	return nc;
}

int getType(client *pClient){
	return pClient->type;
}

int getSortingMethod(client *pClient){
	return pClient->sortingMethod;
}

int getStatus(client *pClient){
	return pClient->status;
}

void startAutomaticClient(client *pClient){
	int id = 1;
	pClient->status = 1;
	pthread_t stopClientThread;
	int burst,priority,waiting = 0;
	printf("Press a key to start the client and then any key to stop it.");
	getchar();
	pthread_create(&stopClientThread, NULL, stopClient, pClient);
	while(pClient->status){
		burst = getRandomNumber(1,MAX_BURST);
		priority = getRandomNumber(1,MAX_PRIORITY);
		waiting = getRandomNumber(1,MAX_WAIT);
		sleep(waiting);
		if(pClient->status)
			printf("\nid: %d, burst: %d, priority: %d, waiting: %d",id,burst,priority,waiting);
		id++;
	}
	pthread_join(stopClientThread, NULL);
	printf("\n");
}

void startManualClient(client *pClient){
	pClient->status = 1;
	/* to-do */
}

int getRandomNumber(int pMinNum, int pMaxNum){
    return (rand() % (pMaxNum - pMinNum + 1)) + pMinNum;
}

/* Thread that controls the status of the client */
void stopClient(client *pClient){
	if(pClient->status){
		getchar();
		printf("\nClient stopped by user.\n");
		turnOffClient(pClient);
	}
	return NULL;
}

/* Sets the status of the client to off */
void turnOffClient(client *pClient){
	pClient->status = 0;
}
