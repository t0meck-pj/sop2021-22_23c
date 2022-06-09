#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (int argc, char* argv[]) {

        int pidPotomka;
	int i;
	int j;
	int suma;
	int liczba;
	
	liczba = atoi(argv[1]);
	pidPotomka = fork();


        if (pidPotomka > 0) {
		waitpid(0,0,0);		
		for( i=0 ; i <= liczba ; i++ ) {
			suma+=i;
		}
                printf("Rodzic, czyli suma: %d\n", suma);
        }
	else {
		for (j=1;j <= liczba;j=j+2) {
		
                printf("Potomek, czyli ciąg liczb nieparzystych: %d\n",j);
	
		}
        }

return 0;
}

