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

int main(){

	int n;
	char wiadomosc [ROZMIAR];
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
	printf("Wpisz teskt wiadomosci\n");
	
	bzero(wiadomosc, ROZMIAR);
	fgets(wiadomosc, ROZMIAR - 1, stdin);
	
	printf("Wysylam wiadomosc\n");
	n = write(gniazdo, wiadomosc, strlen(wiadomosc));
	if(n < 0){
		printf("[-]Blad wyslania wiadomosci\n");
	}
	else{
		printf("[+]Wyslano %d znakow\n", n);
	}
	
	printf("[+]Konczenie programu clienta\n");	
	return 0;
}
