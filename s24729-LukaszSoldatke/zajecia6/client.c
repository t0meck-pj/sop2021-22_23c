#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <strings.h>

char buffer[1024];

int main(int argc, char** argv) {
	int sockfd, port, n, file_size;
	char* requested_file = "file_to_download";
	struct sockaddr_in serv_addr;
        struct hostent *server;
	FILE* destination_file;

	if (argc < 3) {
		printf("Nalezy podac: %s [nazwa hosta] [port]\n", argv[0]);
		exit(0);
	}

	port = atoi(argv[2]);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		printf("Blad podczas tworzenia socketu\n");

	server = gethostbyname(argv[1]);
	if (server == NULL) {
		printf("Blad - nie ma takiego hosta\n");
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *) server -> h_addr, (char *) &serv_addr.sin_addr.s_addr, server -> h_length);
	serv_addr.sin_port = htons(port);

	if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		printf("Blad przy laczeniu\n");

	printf("Zadam pliku: %s\n", requested_file);

	bzero(buffer, sizeof(buffer));
	n = write(sockfd, requested_file, strlen(requested_file));
	if (n < 0)
		printf("Blad zapisu\n");

	bzero(buffer, sizeof(buffer));
	n = read(sockfd, buffer, sizeof(buffer) - 1);
	if (n < 0)
		printf("Blad odczytu\n");

	file_size = atoi(buffer);

        destination_file = fopen("downloaded_file", "w");
        if (destination_file == NULL) {
                printf("Blad - plik nie istnieje\n");
                exit(1);
        }

	printf("Pobieranie pliku\n");
	bzero(buffer, sizeof(buffer));
        n = read(sockfd, buffer, file_size);

        fprintf(destination_file, "%s", buffer);
        printf("Pobrano plik\n");

        fclose(destination_file);
	close(sockfd);

	printf("Rozlaczono\n");

	return 0;
}
