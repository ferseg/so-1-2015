#include "../Headers/client.h"


client* newClient(int pType, int pSortingMethod){
	client *nc = malloc(sizeof(client));
	nc->type = pType;
	nc->sortingMethod = pSortingMethod;
	nc->status = 1;
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

void turnOffClient(client *pClient){
	pClient->status = 0;
}

