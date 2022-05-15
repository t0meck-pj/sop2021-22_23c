#include <stdio.h>

int liczba = 0;
int wynik = 0;

int main() {

	printf("Podaj swoje liczby\nPodaj 0 by przerwac\n");

	do {	
		scanf("%d", &liczba);
		wynik = wynik + liczba;
		printf("Wynik biezacy = %d\n",wynik);
	} while(liczba != 0);

	if(wynik > 255){
        	printf("Wynik przekracza mozliwa wartosc kodu zakonczenia programu (255)\n");
		printf("Wynik nie zostal zapisany\n");
        	return 0;
	}
	
	printf("Wpisz echo $? by zobaczyć ostateczny wynik\n");
	
	return wynik;
}

