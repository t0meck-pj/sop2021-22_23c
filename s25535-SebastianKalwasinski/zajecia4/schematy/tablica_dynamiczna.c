#include <stdio.h>
#include <stdlib.h>

int main(){

	int liczbaElementow;
	int* tablicaDynamiczna;
	int i, j;

	printf("Ile elementow ma miec tablica?\n");
	scanf("%d", &liczbaElementow);
	tablicaDynamiczna = calloc(liczbaElementow, sizeof(int));

	printf("Zapodawaj je:\n");
	for(i = 0; i < liczbaElementow; i++){
		scanf("%d", &tablicaDynamiczna[i]);
	}

	printf("Drukuje zapisane elementy:\n");

	for(j = 0; j < liczbaElementow; j++){
		printf("Element na pozycji %d = %d\n", j, tablicaDynamiczna[j]);
	}
	
	printf("Zwalniam pamiec\n");
	free(tablicaDynamiczna);        /*<--- VERY IMPORTANTE!!!*/
	return 0;
}
