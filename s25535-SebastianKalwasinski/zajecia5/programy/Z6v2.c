#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){

	pid_t pid;
	char koniec[] = "q\n";
	FILE* plik;
	int x = 1;

	plik = fopen("/tmp/czat", "w+");
	if(plik == NULL){
		printf("Blad plikiu\n");
		return 1;
	}

	pid = fork();

	if(pid == 0){
		/*potomek*/
		char wiadomosc[81];
		
		while(x == 1){
			while(access("/tmp/lock", F_OK) == 0){
				fgets(wiadomosc, 80, stdin);
                                fputs(wiadomosc, plik);

				
				fgets(wiadomosc, 80, plik);
				printf("Rodzic napisal: %s", wiadomosc);

				if(strcmp(wiadomosc, koniec) == 0){
					remove("/tmp/lock");
					return 0;
				}
				remove("/tmp/lock");
			}
		}
	}
	if(pid > 0){
		char wiadomosc[81];
		int status = -1;

		printf("Rodzic zaczyna\n");
		fopen("/tmp/lock", "w");
		while(x == 1){
			while(access("/tmp/lock", F_OK) != 0){
				fgets(wiadomosc, 80, stdin);
				fputs(wiadomosc, plik);
				fgets(wiadomosc, 80, plik);
                                printf("Potomek napisal: %s", wiadomosc);
				
				if(strcmp(wiadomosc, koniec) == 0){
                                        x = 0;
					fopen("/tmp/lock", "w");
                                        break;
                                }
				fopen("/tmp/lock", "w");
			}
		}
		wait(&status);
		fclose(plik);
		remove("/tmp/czat");
		remove("/tmp/lock");
		printf("Status = %d\n", status);
	}

	return 0;
}









			


	
