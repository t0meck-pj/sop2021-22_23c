#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <strings.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <signal.h>
#include <sys/stat.h>

#define PORT 5000
#define ROZMIAR 256

void zakoncz(int sygnal){

	printf("\n[+]Gaszenie servera\n");
	exit(1);
}

void wyslij(FILE* plik, int gniazdo_clienta, int rozmiar_pliku){
	
	int n;
	char dane[ROZMIAR];
	
	bzero(dane, ROZMIAR);
	while(rozmiar_pliku > 0){
		fgets(dane, ROZMIAR, plik);
		n = write(gniazdo_clienta, dane, strlen(dane));
		printf("[p]Wysylam:%s", dane);
	        printf("[p]Dlugosc = %d\n\n", n);
		rozmiar_pliku = rozmiar_pliku - n;
	}
}

int main(){

	int n;
	char bufor[ROZMIAR];
	int rozmiar_pliku;
	char rozmiar_dowyslania[ROZMIAR];
	int gniazdo_servera;
	int gniazdo_clienta;
	struct sockaddr_in serv_addr;
	FILE* plik;
	char nazwapliku[256];

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
		printf("[ ]Server czeka...\n");
		gniazdo_clienta = accept(gniazdo_servera, (struct sockaddr*) NULL, NULL);
		
		if(gniazdo_clienta > 0) {
			printf("[+]Gniazdo_clienta ok\n"); 	
		}
		else{
			printf("[-]Blad gniaza clienta\n");
			return 1;
		}
	
		bzero(bufor, ROZMIAR);
		printf("[+]Client sie polaczyl\n");
		
		/*printf("Mozna tutaj wykonywac kod\n");*/

		n = read(gniazdo_clienta, bufor, ROZMIAR - 1);

		if(n < 0){
			printf("[-]Blad odbioru wiadomosci\n");
		}
		else{
			printf("[+]Odebrano %d znakow (nazwa pliku)\n", n);
		}

		strcpy(nazwapliku, bufor);
		printf("[ ]Otrzymana nazwa pliku = %s\n", bufor);

		plik = fopen(nazwapliku, "r");
		if(plik == NULL){
			printf("[-]Blad pliku\n");
			write(gniazdo_clienta, "-1", ROZMIAR -1);
		}
		else{
			printf("[+]Plik otwarto\n");
		

			fseek(plik, 0L, SEEK_END);
			rozmiar_pliku = ftell(plik);
			printf("[ ]Rozmiar pliku u servera (int) = %d\n", rozmiar_pliku);
			rewind(plik);
		
			sprintf(rozmiar_dowyslania, "%d", rozmiar_pliku); 
			printf("[ ]Rozmiar pliku do wyslania (string) = %s\n", rozmiar_dowyslania);
			n = write(gniazdo_clienta, rozmiar_dowyslania, ROZMIAR - 1);
		

			if(n < 0){
				printf("[-]Blad wyslania wiadomosci\n");
			}
			else{
				printf("\n");
				printf("[+]Wyslano %d znakow (rozmiar pliku)\n", n);
			}
	
			wyslij(plik, gniazdo_clienta, rozmiar_pliku);
			printf("[+]Plik wyslano\n");
		}

		if(close(gniazdo_clienta) == 0){
			printf("[+]Polaczenie z clientem zakonczono\n");
		}
		else{
			printf("[-]Blad konczenia polaczenia\n");
		}
	}
	return 0;
}

