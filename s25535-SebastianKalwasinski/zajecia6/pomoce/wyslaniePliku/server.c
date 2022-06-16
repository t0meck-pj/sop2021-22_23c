#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <strings.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <signal.h>

#define PORT 5000
#define ROZMIAR 256

void zakoncz(int sygnal){

	printf("\n[+]Gaszenie servera\n");
	exit(1);
}

void wyslij(FILE* plik, int gniazdo_clienta){
	
	char dane[ROZMIAR] = {0};

	while(fgets(dane, ROZMIAR, plik) != NULL){
			if(write(gniazdo_clienta, dane, sizeof(dane)) == -1){
				printf("[-]Blad wysylania pliku\n");
				exit(1);
			}
	bzero(dane, ROZMIAR);
	}
}

int main(){

	int gniazdo_servera;
	int gniazdo_clienta;
	struct sockaddr_in serv_addr;
	FILE* plik;
	char nazwapliku[] = "plik.txt";

	signal (SIGINT, zakoncz);

	gniazdo_servera = socket(AF_INET, SOCK_STREAM, 0);
	if(gniazdo_servera > 0){
		printf("[+]Gniazdo servera ok\n");
	}
	else{
		printf("[-]Blad gniazda servera\n");
		return 1;
	}

	bzero((char*) &serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);

	if(bind(gniazdo_servera, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == 0){
		printf("[+]Bind ok\n");
	}
	else{
		printf("[-]Blad bind-a\n");
		printf("Byc moze przed chwila zakonczyles server. Poczekaj ze sekunde.\n");
		return 1;
	}

	if(listen(gniazdo_servera, 10) == 0){
		printf("[+]Gniazdo moze sluchac\n");
	}
	else{
		printf("[-]Blad sluchania\n");
		return 1;
	}

	while(1){
		printf("[+]Server czeka...\n");
		gniazdo_clienta = accept(gniazdo_servera, (struct sockaddr*) NULL, NULL);

		if(gniazdo_clienta > 0) {
			printf("[+]Gniazdo_clienta ok\n"); 	
		}
		else{
			printf("[-]Blad gniaza clienta\n");
			return 1;
		}

		printf("[+]Client sie polaczyl\n");
		
		/*printf("Mozna tutaj wykonywac kod\n");*/

		plik = fopen(nazwapliku, "r");
		if(plik == NULL){
			printf("[-]Blad pliku\n");
			return 1;
		}
		else{
			printf("[+]Plik otwarto\n");
		}
		wyslij(plik, gniazdo_clienta);
		printf("[+]Plik wyslano\n");


		if(close(gniazdo_clienta) == 0){
			printf("[+]Polaczenie z clientem zakonczono\n");
		}
		else{
			printf("[-]Blad klonczenia polaczenia\n");
		}
	}
	return 0;
}

