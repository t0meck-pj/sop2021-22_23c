#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[]){
	
	int doDziecka[2];
	int doRodzica[2];
	int pid;
	char koniec[] = "koniec";
	
	pipe(doDziecka);
	pipe(doRodzica);
	
	pid = fork();
	if(pid == 0){
     	/*dziecko*/
		char wiadomosc1[81];
		close(doDziecka[1]);
		close(doRodzica[0]);
		
		while(1){
			
			read(doDziecka[0], &wiadomosc1, sizeof(wiadomosc1));
			printf("Rodzic napisal: %s\n", wiadomosc1);
			
			if(strcmp(wiadomosc1, koniec) == 0){
				break;
			}

			fgets(wiadomosc1, 81, stdin);
			wiadomosc1[strlen(wiadomosc1) - 1] = '\0';
			write(doRodzica[1], &wiadomosc1, sizeof(wiadomosc1));
			/*printf("Wysłano do rodzica: %s\n", wiadomosc1);*/
		}
		close(doRodzica[1]);
		close(doDziecka[0]);
	}
	
	if(pid > 0){
	/*rodzic*/
		char wiadomosc2[81];
		int status = 100;
		close(doDziecka[0]);
		close(doRodzica[1]);
		
		printf("Rodzic zaczyna rozmowe\n");
		while(1){
			
			fgets(wiadomosc2, 81, stdin);
			wiadomosc2[strlen(wiadomosc2) - 1] = '\0';
			write(doDziecka[1], &wiadomosc2, sizeof(wiadomosc2));
			/*printf("Wysłno do dziecka: %s\n", wiadomosc2);*/
			
			read(doRodzica[0], &wiadomosc2, sizeof(wiadomosc2));
			printf("Dziecko napisało: %s\n", wiadomosc2);
			
			if(strcmp(wiadomosc2, koniec) == 0){
				break;
			}
		}
		close(doRodzica[0]);
		close(doDziecka[1]);
		wait(&status);
		/*printf("Status dziecka = %d\n", status);*/
	}
	return 0;
}
