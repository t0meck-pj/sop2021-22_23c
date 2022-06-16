#define _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/syscall.h>
#include <unistd.h>

void konflikt(int);
void skasuj_plik(int);

int main(){

	FILE* plik;
	signal(SIGUSR1, konflikt);
	signal(SIGINT, skasuj_plik);
	
	printf("PID = %d\n", getpid());
	if(access("/tmp/lock", F_OK) != 0){
		plik = fopen("/tmp/lock", "w+");
		fprintf(plik, "%d" , getpid());
		
		while(access("/tmp/lock", F_OK) == 0){
			sleep(100);
		}
	}
	else{
		int pid = 0;
		plik = fopen("/tmp/lock", "w+");
		fscanf(plik, "%d", &pid);
		
		/*raise(SIGUSR1);*/
		kill(pid, SIGUSR1);
	}

        return 0;
}

void konflikt(int numer){

	printf("Nu, nu, nu. Już istenieje.\nNie ma dwoch naraz!\n");
}

void skasuj_plik(int numer){

	printf("\nNastepuje zwolnienie blokady\n");
	remove("/tmp/lock");
}
