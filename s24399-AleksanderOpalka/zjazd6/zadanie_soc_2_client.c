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

int main() {
    int number_of_characters;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	FILE* file;
	char buffer[BUFFER_SIZE];
	
	file=fopen("file_response.txt", "a");

	if(file==NULL){
		printf("[-] Reading response.txt file: Error !\n");
		return 1;
	}else{
		printf("[+] Reading response.txt file: OK !\n");
	}

	server=gethostbyname(SERVER_NAME);
	char requested_file[]="file_source.txt";
	int client_socket=socket(AF_INET,SOCK_STREAM,0);

	if(client_socket<0){
		printf("[-] Creation of socket: Error!\n");
		return 1;
	}else{
		printf("[+] Creation of socket: OK !\n");
	}

	bzero((char *) &serv_addr,sizeof(serv_addr));

	serv_addr.sin_family=AF_INET;
	bcopy((char *)server->h_addr, (char *) &serv_addr.sin_addr.s_addr,server->h_length);
	serv_addr.sin_port=htons(PORT);

	int connect_int=connect(client_socket,(struct sockaddr *) &serv_addr,sizeof(serv_addr));

	if (connect_int<0){
		printf("[-] Connection to server: Error !\n");
		return 1;
	}else{
		printf("[+] Connection to server: OK !\n");
		printf("[ ] Trying to access file: %s \n", requested_file);
	}

	int number_of_characters_write=write(client_socket,requested_file,BUFFER_SIZE-1);
	if (number_of_characters_write<0){
		printf("[-] Writing message to socket: Error!\n");
		return 1;
	}else{
		printf("[+] Writing message to socket: OK!\n");
	}

	bzero(buffer,BUFFER_SIZE);

	int number_of_characters_read=read(client_socket,buffer,BUFFER_SIZE-1);
	if (number_of_characters_read<0){
        printf("[-] Reading message from socket: Error!\n");
		return 1;
	}else{
		printf("[+] Reading message from socket: OK!\n");
	}

	int file_size=atoi(buffer);
	bzero(buffer,BUFFER_SIZE);
	number_of_characters=read(client_socket,buffer,file_size);
	fprintf(file,"%s",buffer);
	fclose(file);

	return 0;
}