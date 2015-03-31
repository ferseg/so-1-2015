#include "../Headers/client.h"


struct client* new_client(int pType, int pSorting_method){
	struct client *nc = (struct client*)(malloc(sizeof(struct client)));
	nc->type = pType;
	nc->sorting_method = pSorting_method;
	nc->status = 1;
	return nc;
}

int get_type(struct client *pClient){
	return pClient->type;
}

int get_sorting_method(struct client *pClient){
	return pClient->sorting_method;
}

int get_status(struct client *pClient){
	return pClient->status;
}

void turn_off_client(){
	
}

