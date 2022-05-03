#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	int i = 0;
	int ile = 0;	        
	int liczby = 0;
	FILE* plik;
	plik = fopen(argv[1], "r");
	
	if(plik == NULL){
		printf("Blad pliku\n");
    		return 1;
	}
	
	fscanf(plik, "%d", &ile);
	for(i = 0; i < ile; i++){
		fscanf(plik, "%d", &liczby);
		printf("Liczba nr.%d = %d\n", i+1, liczby);
	}

	fclose(plik);
	return 0;
}
