#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>

#define PORT 5500
#define BUFFER_SIZE 512
#define SERVER_NAME "localhost"

int main(){

	char buffer [BUFFER_SIZE];
	struct sockaddr_in serv_addr;
    struct hostent *server;

	int client_socket=socket(AF_INET,SOCK_STREAM,0);
	if(client_socket<0){
		printf("[-] Creation of socket: Error!\n");
		return 1;
	}else{
		printf("[+] Creation of socket: OK !\n");
	}

    server=gethostbyname(SERVER_NAME);

	serv_addr.sin_family=AF_INET;
	bcopy((char *)server->h_addr, (char *) &serv_addr.sin_addr.s_addr,server->h_length);
	serv_addr.sin_port=htons(PORT);

	int connect_int=connect(client_socket,(struct sockaddr *) &serv_addr,sizeof(serv_addr));

	if (connect_int<0){
		printf("[-] Connection to server: Error !\n");
		return 1;
	}else{
		printf("[+] Connection to server: OK !\n");
		printf("[ ] Trying to access file: \n");
	}

	printf("Insert your message: \n");	
	bzero(buffer,BUFFER_SIZE);
	fgets(buffer,BUFFER_SIZE-1,stdin);
	int number_of_characters_write=write(client_socket,buffer,strlen(buffer));

	if (number_of_characters_write<0){
		printf("[-] Writing message to socket: Error!\n");
		return 1;
	}else{
		printf("[+] Writing message to socket: OK!\n");
	}
	return 0;
}