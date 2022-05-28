#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


bool sprawdz(unsigned int x);
unsigned int okreslRozmiar(char* sciezka);
void wczytaj(char* sciezka, char* tablica);
void offset(int poz);
void heksy(const char* tablica, int wier, int poz);
void znaczki(const char* tablica, int wier, int poz);

int main(int argc, char** argv) {

	int j;
	int i = 0;
	int pozycja = 0;
	int wiersz = 16;
	unsigned int rozmiar;
	char* tablica;
	char sciezka[100];

	if(argc == 1){
		printf("Nie podales pliku\n");
		exit(3);
	}
	strcpy(sciezka, argv[1]);

	rozmiar = okreslRozmiar(sciezka);
	if(rozmiar <= 0){
		printf("Plik pusty");
		exit(2);
	}

	tablica = calloc(okreslRozmiar(sciezka), sizeof(char));
	wczytaj( sciezka, tablica);
	
	printf("\n");
	while(true) {
		if(wiersz % rozmiar == wiersz){
			offset(pozycja);
			heksy(tablica, wiersz, pozycja);
			znaczki(tablica, wiersz, pozycja);
			printf("\n");
		}
		
		else{
			offset(pozycja);
			heksy(tablica, rozmiar, pozycja);
			for (j = 0; j < wiersz - rozmiar; j++){
				printf(" %c ", 0x20);
			}
			znaczki(tablica, rozmiar, pozycja);
			break;
		}
		i++;
		rozmiar = rozmiar - wiersz;
		pozycja = wiersz * i;
	}
	free(tablica);
	printf("\n\n");
	return 0;
}

bool sprawdz(const unsigned int x){

	if(x >= 32 && x < 127){
		return true;
	}
	
	return false;
}

unsigned int okreslRozmiar(char* sciezka){

    	unsigned int rozmiar;
	FILE *plik;
	plik = fopen(sciezka, "r");

	if (plik == NULL) {
		printf("Nie ma plika\n");
		exit(1);
	}
	
	fseek(plik, 0L, SEEK_END);
	rozmiar = ftell(plik);
	
	fclose(plik);
	return rozmiar;
}

void wczytaj(char* sciezka, char* tablica){

	int i = 0;
	char znak;
	FILE *plik;
	
	plik = fopen(sciezka, "r");
	if (plik == NULL) {
		printf("Nie ma plika\n");
		exit(1);
	}
	
	for (i = 0; i < okreslRozmiar(sciezka); i++){ 

		fscanf(plik, "%c", &znak);
		if(!sprawdz(znak)) {
			tablica[i] = 46;
		}
		else {
				tablica[i] = znak;
		}
	}
	fclose(plik);
}

void offset(int poz){

	printf("%08X ", poz);
}

void heksy(const char* tablica, const int wier, const int poz){
	int i;
	for (i = 0; i < wier; i++) {
		printf("%02X ", tablica[i + poz]);
	}
}

void znaczki(const char* tablica, const int wier, const int poz){
	int i;
	for(i = 0; i < wier; i++){
		printf("%c", tablica[i + poz]); 
		/*if(!sprawdz(tablica[i + poz])){
			printf("%c", 0x2E);
		}
		else {
			printf("%c", tablica[i + poz]);
		}*/
	}
}
