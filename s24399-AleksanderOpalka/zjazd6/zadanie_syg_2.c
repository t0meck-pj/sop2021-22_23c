#define _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_function(){
	printf("Wykryto probe uruchomienia drugiej instancji programu.\n");
}

void sigint_function(){
	remove("/tmp/lock");
}

int main(){

	FILE* file;
	
    signal(SIGUSR1, sigusr1_function);
	signal(SIGINT, sigint_function);	
	printf("My name(PID) is: %d\n", getpid());

	if(access("/tmp/lock",F_OK) != 0){
    	file=fopen("/tmp/lock","w+");
		fprintf(file,"%d",getpid());	
		while(access("/tmp/lock", F_OK) == 0){sleep(10);}
	}
	else{
		int pid=0;
		file=fopen("/tmp/lock","w+");
		fscanf(file,"%d",&pid);
		kill(pid,SIGUSR1);
	}

    return 0;
}
