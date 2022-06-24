#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <signal.h>

int sockfd;
char buffer[1024];

void logger(char* log_msg);
void instance(int socket);

void sigintHandler(int signum) {
	close(sockfd);
	logger("\nZamknieto socket (SIGINT)\nZamykanie serwera\n");
	exit(1);
}

int main(int argc, char** argv) {
	int newsockfd, clilen, port;
	struct sockaddr_in serv_addr, client_addr;
	pid_t pid;

	if (argc < 2) {
		logger("Blad - nie podano portu\n");
		exit(1);
	}

	signal(SIGINT, sigintHandler);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		logger("Blad tworzenia socketu\n");
	} else {
		logger("Utworzono socket\n");
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	port = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		logger("Blad podczas bindowania\n");
	} else {
		logger("Bindowanie zakonczone powodzeniem\n");
	}

	if (listen(sockfd, 5) == 0) {
		logger("Nasluchiwanie\n");
	} else {
		logger("Blad przy nasluchiwaniu\n");
	}

	clilen = sizeof(client_addr);

	while (1) {
		logger("OCZEKIWANIE NA KLIENTA\n");
		newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &clilen);
		if (newsockfd < 0) {
			logger("Blad przy akceptowaniu\n");
		} else {
			logger("Klient nawiazal polaczenie\n");
		}

		pid = fork();
		if (pid < 0) {
			logger("Blad przy forkowaniu\n");
		} else if (pid == 0) {
			close(sockfd);
			instance(newsockfd);
			exit(0);
		} else {
			close(newsockfd);
		}
	}

	return 0;
}

void logger(char* log_msg) {
        FILE* log_file = fopen("server.log", "a");

        fprintf(log_file, "%s", log_msg);
        printf("%s", log_msg);

        fclose(log_file);
}

void instance(int socket) {
	int n;
	FILE* file;

	bzero(buffer, sizeof(buffer));
	n = read(socket, buffer, sizeof(buffer) - 1);
	if (n < 0) {
		logger("Blad odczytu\n");
	}

	printf("Zazadano pliku %s\n", buffer);
	file = fopen(buffer, "r");
	if (file != NULL) {
		int file_size;
                char* file_size_str;

                fseek(file, 0, SEEK_END);
                file_size = ftell(file);
                rewind(file);

                sprintf(file_size_str, "%d", file_size);

                n = write(socket, file_size_str, sizeof(buffer) - 1);
                if (n < 0) {
                        logger("Blad zapisu\n");
                }

                bzero(buffer, sizeof(buffer));
                fgets(buffer, sizeof(buffer), file);
                n = write(socket, buffer, sizeof(buffer) - 1);
                if (n < 0)
                        logger("Blad zapisu\n");
                logger("Przeslano plik\n");

                logger("Klient sie rozlaczyl\n");
	} else {
		logger("Blad - zazadany plik nie istnieje\n");
                write(socket, "-1", 3);
	}
}
