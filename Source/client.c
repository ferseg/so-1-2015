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
		char input;
  	    printf("\nIngrese la letra s para detener el cliente.\n");
		do{
			scanf("%c", & input);
		    if (input == 's') {
		    	pClient->status = 0;
				printf("\nCliente detenido por el usuario.\n");
		    	break;
			}
		}while (input != 's');
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
		switch(selectedOption){
	        case 1:
		        clientType = selectedOption;
				algorithm = selectAlgorithm();
			    c1 = newClient(clientType,algorithm);
  			    startManualClient(c1);
			    return;
		    case 2:
		        clientType = selectedOption;
				algorithm = selectAlgorithm();
			    c1 = newClient(clientType,algorithm);
				startAutomaticClient(c1);
		        return;
	        case 3:
	        	printf("Detenido por el usuario\n\n");
	        	return;
	        default:
	            printf("Opción desconocida.\n\n");
	            break;
	    	}
	} while(selectedOption != '3');
}

int selectAlgorithm(){
	int selectedOption;
	int quantum;
	do {
	    printf("MAIN MENU\n");
	    printf("[1] FIFO\n");
	    printf("[2] SJF\n");
	    printf("[3] SPF\n");
	    printf("[4] Round Robin\n");
	    printf("[5] Salir\n");
	    printf("Seleccione una opción [1, 2, 3,4 ,5]: ");
	    scanf("%d", &selectedOption);
		    switch(selectedOption){
		        case 1:
			        return 0;
		        case 2:
		        	return 1;
		        case 3:
			        return 2;
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

	} while(selectedOption != '5');
}

void startAutomaticClient(client *pClient){
	int id = 1;
	char *message;
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
				asprintf(&message,"%d %d %d ",id,burst,priority);
				sendDataToServer(message);
			}
			sleep(waiting);
			id++;
		}
		pthread_join(stopClientThread, NULL);
	}
}

void startManualClient(client *pClient){
	pClient->status = 1;
	pthread_t stopClientThread;
	int burst,priority,waiting = 0;
	pthread_create(&stopClientThread, NULL, stopClient, pClient);
	/* to-do */
	FILE *file = openFile("input.txt", 'r');
	closeFile(file);
}
