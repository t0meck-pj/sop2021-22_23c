#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

pid_t waitpid(pid_t pid, int *status, int options);

int main(){
    int status=0;
    int index;
    printf("Parent PID: %d and PPID: %d\n",getpid(),getppid());
    for (index = 0; index < 100; index++){
        int process=fork();
        if(process==0){
            printf("Chico numbero: %d PID'o: %d and PPID'o %d\n",index+1,getpid(),getppid());
            return 0;
        }
        wait(&status);
    }
    return 0;
}