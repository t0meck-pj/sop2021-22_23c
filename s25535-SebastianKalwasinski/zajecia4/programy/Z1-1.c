#include <stdio.h>

int main() {
	
	int liczba = 0;
	int wynik = 0;

	printf("Podaj swoje liczby\nPodaj 0 by przerwac\n");
	do {
		scanf("%d", &liczba);
		wynik = wynik + liczba;
		printf("Wynik biezacy = %d\n",wynik);
    	} while(liczba != 0);
 	
	printf("Wynik koncowy = %d\n", wynik);
	return 0;
}

