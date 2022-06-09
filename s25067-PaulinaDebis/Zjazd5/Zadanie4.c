#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {

	int Potomek;
	int i=0;
	int iloscPotomkow;

	if ( (Potomek == 0) && (i != (iloscPotomkow-1) ) ) {
		Potomek = fork();
		i++;
	}
	else return 0;

wait(0);

return 0;
}
