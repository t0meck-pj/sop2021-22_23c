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

void odbierz(int gniazdo){
	
	int n;
	FILE* plik;
	char nazwapliku[] = "plik2.txt";
	char bufor[ROZMIAR];

	plik = fopen(nazwapliku, "w");
	if(plik == NULL){
		printf("[-]Blad pliku\n");
		exit(1);
	}
	else{
		printf("[+]Plik otwarto\n");
	}

	while(1){
		n = read(gniazdo, bufor, ROZMIAR);
		printf("Czytam...\n");
		if(n <=0 ){
			break;
		}
		fprintf(plik, "%s", bufor);
	}
}

int main(){

	int gniazdo;
	struct sockaddr_in serv_addr;

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
	
	printf("[+]Connecting...\n");

	if(connect(gniazdo, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0){
		printf("[+]Gniazdo podłączone do servera\n");
	}
	else{
		printf("[-]Nie polaczono\n");
	       	return 1;
	}

	/*printf("Mozna tutaj wykonywac kod\n");*/
	
	odbierz(gniazdo);

	
	printf("[+]Konczenie programu clienta\n");	
	return 0;
}
