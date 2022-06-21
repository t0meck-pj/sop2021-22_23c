#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>

#define PORT 5500
#define BUFFER_SIZE 512

int client_socket;

void sigint_func(){
    close(client_socket);
    exit(1);
}

void write_to_log(char* string){
    FILE* file;
    file=fopen("log.txt","a");
    fprintf(file,"%s",string);
    fclose(file);
}

int main() {
    signal(SIGINT, sigint_func);
    int serv_socket;
    int number_of_characters;
    struct sockaddr_in serv_addr;
    struct sockaddr_in client_address;
    char buffer[BUFFER_SIZE];

    serv_socket=socket(AF_INET,SOCK_STREAM,0);

    if(serv_socket<0){
        printf("[-] Creation of the socket: Error !\n");
        write_to_log("[-] Creation of the socket: Error !\n");
        return 1;
    }else{
        printf("[+] Creation of the socket: OK !\n");
        write_to_log("[+] Creation of the socket: OK !\n");
    }

    bzero((char *) &serv_addr,sizeof(serv_addr));

    int port=PORT;
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(port);
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);

    int bind_int=bind(serv_socket,(struct sockaddr *) &serv_addr, sizeof(serv_addr));

    if(bind_int<0){
        printf("[-] Binding: Error ! (check if different server instance is running in background) \n");
        write_to_log("[-] Binding: Error ! \n");
        return 1;
    }else{
        printf("[+] Binding: OK ! \n");
        write_to_log("[+] Binding: OK ! \n");
    }

    int listen_int=listen(serv_socket, 10);

    if(listen_int==-1){
        printf("[-] Listening: Error ! (Probably another socket is already listening on the same port.)\n");
        write_to_log("[-] Listening: Error ! \n");
        return -1;
    }    

    while(1) {
        unsigned int client_address_size=sizeof(client_address);
        client_socket=accept(serv_socket,(struct sockaddr *) &client_address,&client_address_size);

        if(client_socket<0){
            printf("[-] Client accepton a socket: Error !\n");
            write_to_log("[-] Client accepton a socket: Error !\n");
            return 1;
        }

        int pid=fork();
        if(pid==0){
            close(serv_socket);
            bzero(buffer,BUFFER_SIZE);

            number_of_characters=read(client_socket,buffer,BUFFER_SIZE-1);
            if (number_of_characters<0){
                printf("[-] Attempt to read up to count bytes from file descriptor: Error!\n");
                write_to_log("[-] Attempt to read up to count bytes from file descriptor: Error!\n");
                return 1;
            }

            FILE *requested_file=fopen(buffer,"a");

            if(requested_file==NULL){
                number_of_characters=write(client_socket,"-1",32);
                if(number_of_characters<0){
                    printf("[-] Attempt to write up to count bytes from buffer: Error!\n");
                    write_to_log("[-] Attempt to write up to count bytes from buffer: Error!\n");
                }
            }else{
                fseek(requested_file,0,SEEK_END);
                int file_size=ftell(requested_file);
                rewind(requested_file);

                char file_size_string[BUFFER_SIZE];
                sprintf(file_size_string,"%d",file_size);

                number_of_characters=write(client_socket,file_size_string,BUFFER_SIZE-1);

                bzero(buffer, BUFFER_SIZE);

                while(file_size>0){
                    fgets(buffer,file_size,requested_file);
                    int number_of_characters=write(client_socket,buffer,BUFFER_SIZE-1);

                    if(number_of_characters<0){
                        printf("[-] Sending file content: Error !\n");
                        write_to_log("[-] Sending file content: Error !\n");
                    }else{
                        printf("[+] Sending file content: OK !\n");
                        write_to_log("[+] Sending file content: OK !\n");
                    }
                    file_size=file_size-number_of_characters;
                }
            }
            fclose(requested_file);
            return 0;
        }else{
            wait(0);
            close(client_socket);
            break;
        }
    }
    return 0;
}
