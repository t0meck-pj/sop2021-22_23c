#include <stdio.h>
#include <stdlib.h>


void wyswietl(int rozmiar, int tablica[]){
	
	int i;
	
	for(i = rozmiar-1; i >= 0; i--){
		printf("Pozycja %d = %d\n", i, tablica[i]);
	}
}


int main(int argc, char* argv[]){

	int i, rozmiar, liczba;
	FILE* plik;
	int * tablica;
	plik = fopen(argv[1], "r");

	if(plik == NULL){
		printf("Ile liczb wczytać\n");
		if(scanf("%d", &rozmiar) == 0){
			printf("Nie podales liczby :( foch!\n");
		}
		else{
			tablica = calloc(rozmiar, sizeof(int));
			printf("Dawaj je!\n");

		
			for(i = 0; i < rozmiar; i++){
				if(scanf("%d", &liczba) == 0){
					printf("To nie jest liczba, wstawiam 0\n");
					tablica[i] = 0;
					getchar();
				}
				else{tablica[i] = liczba;}
			}
			wyswietl(rozmiar, tablica);
			free(tablica);
		}
	}

	else{
		fscanf(plik, "%d", &rozmiar);
		tablica = calloc(rozmiar, sizeof(int));
		printf("Rozmiar tablicy = %d\n", rozmiar);
	
		for(i = 0; i < rozmiar; i++){
			fscanf(plik, "%d", &tablica[i]);
		}

		fclose(plik);
		wyswietl(rozmiar, tablica);
		free(tablica);
	}
	return 0;
}
