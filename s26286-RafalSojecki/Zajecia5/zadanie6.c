/*
Napisz prosty program chat-u, który będzie korzystał z pliku w katalogu /tmp
do przekazywania wiadomości. Zastanów się jak to zrobić.
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    pid_t pid;
    FILE *file;
    int x = 1;

    file = fopen("/tmp/chat", "a");
    if (file == NULL)
    {
        return 1;
    }

    pid = fork();

    if (pid == 0)
    {
        time_t mytime = time(NULL);
        char *time_str = ctime(&mytime);
        time_str[strlen(time_str) - 1] = '\0';
        printf("Current Time : %s\n", time_str);
        fputs(time_str, file);
        fputs("\n", file);

        char responseMessage[128];
        char message[128];
        while (1)
        {
            fseek(file, 0, SEEK_END);
            printf("%s\n", responseMessage);
            printf("User 1: \n");
            fgets(message, 128, stdin);
            fputs("User 1:\n", file);
            fputs(message, file);
        }
    }
    if (pid > 0)
    {
        char responseMessage[128];
        char message[128];
        int status = -1;
        while (1)
        {
            fseek(file, 0, SEEK_END);
            printf("%s\n", responseMessage);
            printf("User 2: \n");
            fgets(message, 128, stdin);
            fputs("User 2:\n", file);
            fputs(message, file);
        }
        wait(&status);
        fclose(file);
    }

    return 0;
}
