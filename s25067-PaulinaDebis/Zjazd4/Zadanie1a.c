#include <stdio.h>

int main(){

	int x=0;
	int y=0;
	int wynik=0;

	printf("Podaj dwie liczby:\n");
	scanf("%d %d", &x, &y);
	wynik=x+y;
	printf("Suma wynosi: ");
	printf("Twój wynik: %d\n", wynik);
	return 0;
}

