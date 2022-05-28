#include <stdio.h>
#include <stdlib.h>

typedef int (*f)(int, int);

void readFunctionChoice(int* functionId);
void checkFunctionExist(int functionId);
void readElementCount(int* elementCount);
void checkEnteredNumbers(int elementCount);
void readElements(int* tab, int elementCount);
int sum(int x, int y);
int min(int x, int y);
int max(int x, int y);
int forAll(int* tab, int elementCount, f function);

int main() {
	int functionId, elementCount, result;
	int* tab;

	f tabOfPtrs[3];
	f sumFun = sum;
	f minFun = min;
	f maxFun = max;
  
	tabOfPtrs[0] = sumFun;
	tabOfPtrs[1] = minFun;
	tabOfPtrs[2] = maxFun;

	readFunctionChoice(&functionId);
  	checkFunctionExist(functionId);
	readElementCount(&elementCount);
	checkEnteredNumbers(elementCount);
	
	tab = malloc(elementCount * sizeof(int));

	readElements(tab, elementCount);
	result = forAll(tab, elementCount, tabOfPtrs[functionId]);
  
	printf("Wynik: %d \n", result);

	free(tab);
	return 0;
}

void readFunctionChoice(int* functionId) {
	printf("Dostepne funkcje: \n 0. suma\n 1. minimum\n 2. maksimum\n");
	printf("Twoj wybor: ");
	if (scanf("%d", functionId)) {};
}

void checkFunctionExist(int functionId) {
	if (functionId >= 3 || functionId < 0) {
		printf("Taka funkcja nie istnieje \n");
		exit(1);
	}

	return;
}

void readElementCount(int* elementCount) {
	printf("Podaj ilosc liczb ktore zamierzasz wprowadzic: ");
	if (scanf("%d", elementCount)) {};
}

void checkEnteredNumbers (int elementCount) {
	if (elementCount <= 1) {
		printf("Wprowadziles za malo liczb \n");
		exit(2);
	}

	return;
}

void readElements(int* tab, int elementCount) {
	int i = 0;
  
	printf("Wprowadz te liczby: \n");
	for (i = 0; i < elementCount; i++) {
		if (scanf("%d", &tab[i])) {};
	}
}

int sum(int x, int y) {
	return x + y;
}

int min(int x, int y) {
	return x < y ? x : y;
}

int max(int x, int y) {
	return x > y ? x : y;
}

int forAll(int* tab, int elementCount, f function) {
	int v, i = 0;
	v = tab[0];

	for (i = 1; i < elementCount; i++) {
		v = function(v, tab[i]);
	}

	return v;
}
