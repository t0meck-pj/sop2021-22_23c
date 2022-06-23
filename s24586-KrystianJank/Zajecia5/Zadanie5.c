#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 
  
int main()
{
    int i;
    for (i=0;i<100;i++){
    	int p=fork();
    	
    	if(p == 0){
    		printf("PID dziecka %d,PPID %d \n",getpid(),getppid());
    		return 0;
		}
    }
    int status =0;
    for(i=0;i<100;i++){
    	waitpid(0,&status,0);
	}	
    	
	
    return 0;  
}