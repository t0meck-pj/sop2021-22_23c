#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>

#define PORT 5013
#define SERVER_NAME "szuflandia"
#define BUFFER_SIZE 256

int main() {
	int client_socket, number_of_characters;
	struct sockaddr_in server_address;
	struct hostent *server;
	char buffer[BUFFER_SIZE];

	//test
	char requested_file[] = "file.txt";

	client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket < 0) {
		printf("ERROR: Got problem when creating the socket!\n");
		return 1;
	}

	bzero((char *) &server_address, sizeof(server_address));

	server = gethostbyname(SERVER_NAME);

	if (server == NULL) {
		printf("ERROR: Got problem when searching for the server!\n");
		return 1;
	}

	server_address.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
	server_address.sin_port = htons(PORT);

	if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
		printf("ERROR: Got problem when trying to connect with the server!\n");
		return 1;
	}

	printf("INFO: You are succesfully connected with the server!\n");
	printf("INFO: You are asking for: %s file\n", requested_file);

	number_of_characters = write(client_socket, requested_file, BUFFER_SIZE - 1);
	if (number_of_characters < 0) {
		printf("ERROR: Got problem when write message to the socket!\n");
		return 1;
	}

	bzero(buffer, BUFFER_SIZE);

	number_of_characters = read(client_socket, buffer, BUFFER_SIZE -1);

	if (number_of_characters < 0) {
                printf("ERROR: Got problem when read message from the socket!\n");
                return 1;
        }

	int file_size = atoi(buffer);
	bzero(buffer, BUFFER_SIZE);

	FILE* file;
	file = fopen("response.txt", "w");

	if(file == NULL){
		printf("ERROR: No file!\n");
		return 1;
	}

	number_of_characters = read(client_socket, buffer, file_size);
	fprintf(file, "%s", buffer);
	fclose(file);

	return 0;
}
