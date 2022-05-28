#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){

	pid_t PID_warunkowy;
	int liczba, i, j;
	int suma = 0;
	int status = 100;
	
	if(argc == 1){
		printf("Nie podano argumentu\n");
		return 1;
	}
	liczba = atoi(argv[1]);
	printf("\n");
	PID_warunkowy = fork();
	
	if(PID_warunkowy > 0){
		
		wait(&status);
		printf("\nJestem rodzicem\n");
		
		for(i = 0; i <= liczba; i++){
			suma = suma + i;
		}
		printf("Oto moja suma: %d\n", suma);
	}
	else{
		printf("Jestem dzieckiem\n");
		printf("Oto moje liczby:\n");
		
		for(j = 1; j <= liczba; j+=2){
			printf("%d, ",j);
			if((j%16) == 15) printf("\n");
		}
		printf("\n");
	}
	printf("Status = %d\n", status);
	if(status == 0) printf("\n");
	return 0;
}
