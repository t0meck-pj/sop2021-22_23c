#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main() 
{
	int i;
	pid_t main_process_pid = getpid(), pid;

	printf("Parent_PID: %d\n", main_process_pid);
	
	int n = 100;
    	for (i = 0; i <= n; i++) 
    	{
        	if (fork() == 0) 
        	{
           		printf("Child_num: %d, Child_PID: %d, PPID: %d \n", i, getpid(), getppid());
            		return 0;
        	}
	wait(0);
	sleep(1);
    	}
    
    	for (i = 0; i <= n; i++)
    	{
        	waitpid(0, 0, 0);
    	}

    	return 0;
}
 
