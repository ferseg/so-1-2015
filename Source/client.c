#include "../Headers/client.h"

client* newClient(int pType, int pSortingMethod){
	client *nc = malloc(sizeof(client));
	nc->type = pType;
	nc->sortingMethod = pSortingMethod;
	nc->status = 0;
	return nc;
}

int getRandomNumber(int pMinNum, int pMaxNum){
	srand ( time(NULL) );
    return (rand() % (pMaxNum - pMinNum + 1)) + pMinNum;
}

/* Thread that controls the status of the client */
void stopClient(client *pClient){
	if(pClient->status){
		char input;
  	    printf("\nIngrese la letra s para detener el cliente.\n");
		do{
			scanf("%c", &input);
		    if (input == 's') {
		    	pClient->status = 0;
				printf("\nCliente detenido por el usuario.\n");
		    	break;
			}
		} while (input != 's');
	}
}

void startClient(){
	int selectedOption,clientType,algorithm;
	client *c1;
	do {
	    printf("MAIN MENU\n");
	    printf("[1] Cliente manual\n");
	    printf("[2] Cliente Automático\n");
	    printf("[3] Salir\n");
	    printf("Seleccione una opción [1, 2, 3]: ");
	    scanf("%d", &selectedOption);
	    clientType = selectedOption;
		algorithm = selectAlgorithm();
	    c1 = newClient(clientType,algorithm);
		switch(selectedOption){
	        case 1:
  			    startManualClient(c1);
			    return;
		    case 2:
				startAutomaticClient(c1);
		        return;
	        case 3:
	        	printf("Detenido por el usuario\n\n");
	        	return;
	        default:
	            printf("Opción desconocida.\n\n");
	            break;
	    	}
	} while(selectedOption < 3);
}

int selectAlgorithm(){
	int selectedOption;
	int quantum;
	do {
	    printf("MAIN MENU\n");
	    printf("[1] FIFO\n");
	    printf("[2] SJF\n");
	    printf("[3] HPF\n");
	    printf("[4] Round Robin\n");
	    printf("[5] Salir\n");
	    printf("Seleccione una opción [1, 2, 3,4 ,5]: ");
	    scanf("%d", &selectedOption);
		    switch(selectedOption){
		        case 1:
		        case 2:
		        case 3:
		        	return selectedOption - 1;
		        case 4:
		        	printf("Ingrese un quantum: ");
	    			scanf("%d", &quantum);
		        	return 3+quantum;
		        case 5:
		        	printf("Detenido por el usuario\n\n");
		        	return -1;
		        default:
		            printf("Opción desconocida.\n\n");
		            break;
	    	}
	} while(selectedOption < 5);
}

void startAutomaticClient(client *pClient){
	int id = 1;
	char *message = malloc(sizeof(char)*500);
	pClient->status = 1;
	pthread_t stopClientThread;
	int burst,priority,waiting = 0;
	pthread_create(&stopClientThread, NULL, stopClient, pClient);
	if(testConnection()){
		asprintf(&message,"%d",pClient->sortingMethod);
		sendDataToServer(message);
		while(pClient->status){
			burst = getRandomNumber(1,MAX_BURST);
			priority = getRandomNumber(1,MAX_PRIORITY);
			waiting = getRandomNumber(1,MAX_WAIT);
			if(pClient->status){
				message = malloc(sizeof(char)*500);
				asprintf(&message,"%d %d %d ",id,burst,priority);
				pthread_t serverSenderThread;
			    pthread_create(&serverSenderThread, NULL, sendDataToServer, message);
			}
			sleep(waiting);
			id++;
		}
		sendDataToServer("1000");
		pthread_join(stopClientThread, NULL);
	}
}

void startManualClient(client *pClient) {
	char *message;
	pClient->status = 1;
	pthread_t stopClientThread;
	int burst,priority,waiting = 0;
	pthread_create(&stopClientThread, NULL, stopClient, pClient);
	if(testConnection()){
		clearString(&message, 500);
		asprintf(&message,"%d",pClient->sortingMethod);
		sendDataToServer(message);
		
		FILE *file = openFile("input.txt", "r");
		if (!file) {
			puts("El archivo no existe");
			return;
		}
		while(pClient->status && !feof(file)){
			waiting = getRandomNumber(1,MAX_WAIT);
			clearString(&message, 500);
			getNextLine(file, message);
			pthread_t serverSenderThread;
			pthread_create(&serverSenderThread, NULL, sendDataToServer, message);
			sleep(waiting);
		}
		clearString(&message, 500);
		asprintf(&message,"%d",1000);
		sendDataToServer(message);
		closeFile(file);
		pClient->status = 0;
		pthread_join(stopClientThread, NULL);
	}
}

void clearString(char *str, int len) {
	str = malloc(sizeof(char)*len);
	while(--len > -1) {
		str[len] = 0;
	}
}
