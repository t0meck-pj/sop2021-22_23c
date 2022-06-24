#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void sigUsrFn()
    {
	    printf("Wykryto probe uruchomienia drugiej instancji programu.\n");
      exit(1);
    }

void sigIntFn()
    {
    	remove("/tmp/lock");
    }
	
int main() 
{
    FILE* file;
    
    signal(SIGUSR1, sigUsrFn);
  	signal(SIGINT, sigIntFn);
    
    file = fopen("/tmp/lock", "r");
    
  if (file) 
    {
        int pid;
        fscanf(file, "%d", &pid);
        fclose(file);
        
        while(1) 
        { sleep(1);}       
    }
    else
    {
      int pid;
		  file=fopen("/tmp/lock","w+");
		  fscanf(file,"%d",&pid);
      
		  kill(pid,SIGUSR1);
    }
    
    return 0;
}
