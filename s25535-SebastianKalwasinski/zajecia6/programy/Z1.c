#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>


/*kill -sigusr1 "pid" by wyslac sygnal*/

void stoper();
void nazwafunkcji(int);
int main(){

	signal (SIGUSR1, nazwafunkcji);

	printf("Moj pid = %d\nTeraz spie\n", getpid());
	
	stoper();
	while(1){sleep(10);}
	return 0;
}

void stoper(){
	sleep(3);
	raise(SIGUSR1);
}

void nazwafunkcji(int numer_sygnalu){

	printf("Signal nr.%d got me! I'm out!\n", numer_sygnalu);
	exit(1);
}
