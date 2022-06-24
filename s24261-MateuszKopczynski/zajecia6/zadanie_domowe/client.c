#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define SIZE 1024

void getFile(int sock, int file_size);

int main(int argc, char *argv[]) {
    int sockfd, port, file_size, n;
    char buffer[SIZE];
    char filename[] = "index.html";

    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        printf("[-] Usage %s hostname port \n", argv[0]);
        exit(0);
    }

    port = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        printf("[-] Error opening socket \n");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("[-] Error no such host \n");
    }

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        printf("[-] Error connecting \n");

    bzero(buffer, SIZE);
    printf("[+] Sent filename: %s \n", filename);

    n = write(sockfd, filename, SIZE - 1);
    if (n < 0)
        printf("[-] Error writing to socket \n");

    bzero(buffer, SIZE);

    n = read(sockfd, buffer, SIZE - 1);
    if (n < 0)
        printf("[-] Error reading from socket \n");

    file_size = atoi(buffer);

    getFile(sockfd, 20);
    printf("[+] Disconnected \n");

    return 0;
}

void getFile(int sock, int file_size) {
    int n;
    char buffer[SIZE];
    FILE* file;

    bzero(buffer, SIZE);

    file = fopen("response.html", "w");
    if (file == NULL) {
        printf("[-] File does not exist \n");
        exit(1);
    }
    else { printf("[+] File was find on the server \n"); }

    n = read(sock, buffer, file_size);
    fprintf(file, "%s", buffer);

    printf("[+] File downloaded as received_file.txt \n");

    fclose(file);
}
