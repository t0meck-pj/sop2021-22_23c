#include <stdio.h>

int main(int argc,char *argv[]){

	int i;

	printf("Ilosc twoich argumentow = %d\n", argc-1);
	printf("argc = %d\n", argc);

	printf("Zawartosc argv: \n");
	for(i = 0; i < argc; i++){
		printf("Argument pozycja: %d = %s\n", i, argv[i]);
	}

	return 0;
							        
}
