#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>

#define SIZE 1024

void run(int);
void sendFile(FILE* file, int sock, int file_size);
void createLog(char* log);

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, clilen, port, pid;
    struct sockaddr_in server_addr, client_addr;

    if (argc < 2) {
        printf("[-] Error no port provided \n");
        createLog("[-] Error no port provided \n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("[-] Error opening socket \n");
        createLog("[-] Error opening socket \n");
    }
    printf("[+] Server socket was created \n");
    createLog("[+] Server socket was created \n");

    bzero((char *) &server_addr, sizeof(server_addr));

    port = atoi(argv[1]);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == 0) {
        printf("[+] Binding successful \n");
        createLog("[+] Binding successful \n");
    } else {
        printf("[-] Error on binding \n");
        createLog("[-] Error on binding \n");
    }

    if (listen(sockfd, 5) == 0) {
        printf("[+] Listening \n");
        createLog("[+] Listening \n");
    } else {
        printf("[-] Error on listening \n");
        createLog("[-] Error on listening \n");
    }

    clilen = sizeof(client_addr);

    while (1) {
        printf("Waiting... \n");
        newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &clilen);
        if (newsockfd > 0) {
            printf("[+] Client connected \n");
            createLog("[+] Client connected \n");
        } else {
            printf("[-] Error on accept \n");
            createLog("[-] Error on accept \n");
        }

        pid = fork();
        if (pid < 0) {
            printf("[-] Error on fork \n");
            createLog("[-] Error on fork \n");
        }
        if (pid == 0)  {
            close(sockfd);
            run(newsockfd);
            exit(0);
        }
        else close(newsockfd);
    }

    return 0;
}

void run (int sock) {
    int n, file_size_int;
    char buffer[SIZE];
    char file_size_string[SIZE];
    FILE* file;

    bzero(buffer, SIZE);
    n = read(sock,buffer,SIZE - 1);
    if (n < 0) {
        printf("[-] Error reading from socket");
        createLog("[-] Error reading from socket");
    }
    printf("Received file name: %s \n", buffer);

    file = fopen(buffer, "r");
    if (file == NULL) {
        printf("[-] File does not exist \n");
        createLog("[-] File does not exist \n");
        write(sock, "-1", SIZE - 1);
    } else {
        printf("[+] File was find and opened \n");
        createLog("[+] File was find and opened \n");

        fseek(file, 0, SEEK_END);
        file_size_int = ftell(file);
        rewind(file);

        sprintf(file_size_string, "%d", file_size_int);

        n = write(sock, file_size_string, SIZE - 1);
        if (n < 0) {
            printf("[-] Error writing to socket");
            createLog("[-] Error writing to socket");
        }

        sendFile(file, sock, file_size_int);
        printf("[+] Client disconnected \n");
        createLog("[+] Client disconnected \n");
    }
}

void sendFile(FILE* file, int sock, int file_size) {
    int n;
    char buffer[SIZE];

    bzero(buffer, SIZE);
    while(file_size > 0) {
        fgets(buffer, SIZE, file);
        n = write(sock, buffer, SIZE - 1);
        if (n < 0) {
            printf("[-] Error writing to socket \n");
            createLog("[-] Error writing to socket \n");
        }
        file_size = file_size - n;
    }

    printf("[+] File was sent \n");
    createLog("[+] File was sent \n");
}

void createLog(char* log) {
    FILE* file;

    file = fopen("logs.txt", "a");
    fprintf(file, "%s", log);

    fclose(file);
}

