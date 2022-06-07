#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    
    for(i = 0; i < 10; i++)
    {   
        pid_t pid = fork();
        
        if(pid>0)
        {
            wait(NULL);
            break;
        }
        
        else
        {
             printf("i=%d PID:%d\tPPID:%d\n",i ,getpid(), getppid());
        }
       
    }
    
    return 0;
}
