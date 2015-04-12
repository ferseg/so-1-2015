#include "../Headers/client.h"
#include "../Headers/socket.h"

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

void startClient(){
	char menu;
	do {
	    printf("MAIN MENU\n");
	    printf("[1] Cliente manual\n");
	    printf("[2] Cliente Automático\n");
	    printf("[3] Salir\n");
	    printf("Seleccione una opción [1, 2, 3]: ");
	    scanf("%c", &menu);
	    if(menu != "3"){
		    switch(menu){
		        case '1':
			        
			        break;
		        case '2':
		            
		            break;
		        default:
		            printf("Opción desconocida.\n\n");
		            break;
	    	}
	    } // switch
	} while(menu != '3');




}

void startAutomaticClient(client *pClient){
	int id = 1;
	pClient->status = 1;
	pthread_t stopClientThread;
	int burst,priority,waiting = 0;
	pthread_create(&stopClientThread, NULL, stopClient, pClient);
	if(testConnection()){
		while(pClient->status){
			burst = getRandomNumber(1,MAX_BURST);
			priority = getRandomNumber(1,MAX_PRIORITY);
			waiting = getRandomNumber(1,MAX_WAIT);
			if(pClient->status){
				char *message;
				pthread_t sendDataThread;
				asprintf(&message,"%d %d %d",id,burst,priority);
				pthread_create(&sendDataThread, NULL, sendDataToServer, message);
				pthread_join(sendDataThread, NULL);
			}
			sleep(waiting);
			id++;
		}
		pthread_join(stopClientThread, NULL);
	}
}

void startManualClient(client *pClient){
	pClient->status = 1;
	/* to-do */
}

