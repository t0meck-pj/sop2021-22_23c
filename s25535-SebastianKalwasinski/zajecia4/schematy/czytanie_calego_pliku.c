#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

	char znak;
	FILE* plik;

	plik = fopen(argv[1], "r");
	if(plik == NULL){
		printf("Nie podales pliku\n");
		return 1;
	}
	
	printf("POCZATEK\n");
	do {
		znak = fgetc(plik);
		printf("%c", znak);
	} while(znak != EOF);
	printf("\nKONIEC\n");
	
	fclose(plik);
	return 0;
}
