#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256
#define PORT 5013

int client_socket;

void sigIntFunction() {
    printf("\nINFO:Server has been failed successfully! :P\n");
    close(client_socket);

    exit(1);
}

void printMessageToLogFile(char* message) {
    FILE* file;

    file = fopen("logs.txt", "a");
    fprintf(file, "%s", message);

    fclose(file);
}

int main() {
    signal(SIGINT, sigIntFunction);
    int server_socket, number_of_characters;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0) {
        printf("ERROR: Cannot create the socket!\n");
        printMessageToLogFile("Error: Cannot create the socket!\n");
        return 1;
    }

    //set all values of server_address to zeros.
    bzero((char *) &server_address, sizeof(server_address));

    server_address.sin_family = AF_INET;
    int port = PORT;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("ERROR: Got problem with binding!\n");
        printMessageToLogFile("Error: Got problem with binding!\n");
        return 1;
    }

    listen(server_socket, 5);
    printf("INFO: Server Socket is listening... \n");
    printMessageToLogFile("INFO: Server Socket is listening... \n");

    while(1) {
        int client_address_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_size);

        if (client_socket < 0) {
            printf("ERROR: Got problem with client acceptation!\n");
            printMessageToLogFile("ERROR: Got problem with client acceptation!\n");
            return 1;
        }

        int pid = fork();
        switch (pid) {
            case 0:
                close(server_socket);

                bzero(buffer, BUFFER_SIZE);

                //start: reading...
                number_of_characters = read(client_socket, buffer, BUFFER_SIZE - 1);
                if (number_of_characters < 0) {
                    printf("ERROR: Got problem with reading from the Client Socket!\n");
                    printMessageToLogFile("ERROR: Got problem with reading from the Client Socket!\n");
                    return 1;
                }

                FILE *requested_file = fopen(buffer, "r");

                if (requested_file == NULL) {
                    number_of_characters = write(client_socket, "-1", 18);
                    if (number_of_characters < 0) {
                        printf("ERROR: Got problem with writing to The Client Socket!\n");
                        printMessageToLogFile("ERROR: Got problem with writing to The Client Socket!\n");
                    }
                } else {
                    fseek(requested_file, 0L, SEEK_END);
                    int file_size = ftell(requested_file);
                    rewind(requested_file);

                    char file_size_string[BUFFER_SIZE];
                    sprintf(file_size_string, "%d", file_size);

                    number_of_characters = write(client_socket, file_size_string, BUFFER_SIZE - 1);

                    if (number_of_characters < 0) {
                        printf("ERROR: Got problem with writing to The Client Socket!\n");
                        printMessageToLogFile("ERROR: Got problem with writing to The Client Socket!\n");
                    }

                    bzero(buffer, BUFFER_SIZE);
                    while(file_size > 0) {
                        fgets(buffer, file_size, requested_file);

                        number_of_characters = write(client_socket, buffer, BUFFER_SIZE - 1);

                        if (number_of_characters < 0) {
                            printf("ERROR: Got problem with sending file content!\n");
                            printMessageToLogFile("ERROR: Got problem with sending file content!\n");
                        }

                        file_size = file_size - number_of_characters;
                    }
                }
                //stop: reading.

                printf("INFO: File has been send!\n");
                printMessageToLogFile("INFO: File has been send!\n");
                fclose(requested_file);
                return 0;
            default:
                wait(0);
                close(client_socket);
                break;
        }
    }

    return 0;
}
