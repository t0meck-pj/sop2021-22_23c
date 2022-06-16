#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 5000
#define IP "127.0.0.1"
#define ROZMIAR 256

void odbierz(int gniazdo, int rozmiar_pliku){
	
	int n;
	FILE* plik;
	char bufor[ROZMIAR];
	bzero(bufor, ROZMIAR);

	plik = fopen("odebrany.txt", "w");
	if(plik == NULL){
		printf("[-]Blad pliku\n");
		exit(1);
	}
	else{
		printf("[+]Plik otwarto\n");
	}
	n = read(gniazdo, bufor, rozmiar_pliku);
	fprintf(plik, "%s", bufor);
	printf("[ ]Zapisano:\n %s", bufor);
	printf("[ ]Zapisano %d znakow\n", n);
	fclose(plik);

	/*while(rozmiar_pliku ){
		n = read(gniazdo, bufor, ROZMIAR);
		printf("Czytam...\n");
		if(n <=0 ){
			break;
			return;
		}
		fprintf(plik, "%s", bufor);*/
	
}

int main(){

	int n;
	int gniazdo;
	int rozmiar_pliku;
	struct sockaddr_in serv_addr;
	char nazwapliku[] = "plik.txt";
	char bufor[ROZMIAR];

	gniazdo = socket(AF_INET, SOCK_STREAM, 0);
	if(gniazdo > 0){
	       	printf("[+]Gniazdo ok\n");
	}
	else{
		printf("[-]Blad gniazda\n");
	       	return 1;
	}
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(IP);
	serv_addr.sin_port = htons(PORT);
	
	printf("[ ]Connecting...\n");

	if(connect(gniazdo, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0){
		printf("[+]Gniazdo podłączone do servera\n");
	}
	else{
		printf("[-]Nie polaczono\n");
	       	return 1;
	}

	/*printf("Mozna tutaj wykonywac kod\n");*/
	
	printf("[ ]Wysylam nazwe = %s\n", nazwapliku);
	n = write(gniazdo, nazwapliku, ROZMIAR - 1);
	if(n < 0){
		printf("[-]Blad wyslania wiadomosci\n");
	}
	else{
		printf("[+]Wyslano %d znakow (nazwa pliku) \n", n);
	}	
	n = read(gniazdo, bufor, ROZMIAR - 1);

	if(n < 0){
		printf("[-]Blad odbioru wiadomosci\n");
	}
	else{
		printf("[+]Odebrano %d znakow (rozmiar pliku)\n", n);
	}

	printf("[ ]Rozmiar pliku (string)= %s\n", bufor);
	rozmiar_pliku = atoi(bufor);
	printf("[ ]Rozmiar pliku (int) = %d\n", rozmiar_pliku);
	
	if(rozmiar_pliku < 0){
		printf("[-]Nie ma takiego pliku\n");
		return 1;
	}
	printf("[+]Obieram plik\n");	
	odbierz(gniazdo, rozmiar_pliku);
	
	printf("[+]Konczenie programu clienta\n");	
	return 0;
}
