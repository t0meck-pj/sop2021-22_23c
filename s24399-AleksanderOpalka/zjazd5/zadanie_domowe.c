#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

pid_t waitpid(pid_t pid, int *status, int options);

int main(){
    
    pid_t parent_pid=getpid();
    pid_t main_fork=fork();


    if (main_fork>0){
        printf("Main process (lvl 0) PID:%d \n",getpid());
        main_fork=fork();
    }
    if(main_fork==0){

        pid_t children_parent_pid=getpid();
        pid_t sub_main_fork=fork();

        if(sub_main_fork>0){
            printf("Sub main process (lvl 1) PID:%d \n",getpid());
            sub_main_fork=fork();
        }

        if(sub_main_fork==0){
            printf("Sub sub main process (lvl 2) PID:%d \n",getpid());
        }

    }
    
    
    return 0;
}