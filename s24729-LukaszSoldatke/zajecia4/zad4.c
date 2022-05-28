#include <stdio.h>
#include <stdlib.h>

typedef int (*function)(int,int);

int maksimum(int a, int b);
int minimum(int a, int b);
int suma(int a, int b);
int forAll(int* numbers, int elementCount, function f);

int main() {
	function functions[] = {maksimum, minimum, suma};
	int functionId = 0;
	int elementCount = 0;
	int wynik = 0;
	int i = 0;
	int* numbers;

	printf("Podaj numer funkcji (0 - maksimum, 1 - minimum, 2 - suma): ");
	scanf("%d", &functionId);
	switch (functionId) {
		case 0: printf("Wybrano maksimum\n"); break;
		case 1: printf("Wybrano minimum\n"); break;
		case 2: printf("Wybrano sume\n"); break;
		default: printf("Podano niepoprawna wartosc\n"); break;
	}
	while (functionId < 0 || functionId > 2) {
		printf("Podaj poprawna wartosc z zakresu 0-2: ");
		scanf("%d", &functionId);
	}

	printf("Podaj ilosc elementow ciagu: ");
	scanf("%d", &elementCount);
	while (elementCount < 0) {
		printf("Podaj poprawna wartosc: ");
		scanf("%d", &elementCount);
	}

	numbers = calloc(elementCount, sizeof(int));

	for (i = 0; i < elementCount; i++) {
		printf("Podaj %d element: ", i);
		scanf("%d", &numbers[i]);
	}

	wynik = forAll(numbers, elementCount, functions[functionId]);
	printf("Wynik programu: %d", wynik);

	printf("\n");
	free(numbers);
	return 0;
}

int maksimum(int a, int b) {
	if (a > b) {
		return a;
	} else if (b > a) {
		return b;
	} else {
		return a;
	}
}

int minimum(int a, int b) {
	if (a < b) {
		return a;
	} else if (b < a) {
		return b;
	} else {
		return a;
	}
}

int suma(int a, int b) {
        return a + b;
}

int forAll(int* numbers, int elementCount, function f) {
	int v, i = 0;
	v = numbers[0];

	for (i = 1; i < elementCount; i++) {
		v = f(v, numbers[i]);
	}

	return v;
}
