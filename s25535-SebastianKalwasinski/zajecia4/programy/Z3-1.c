#include <stdio.h>
#include <stdlib.h>


typedef int (*f)(int, int);
int sum(int a, int b);
int min(int a, int b);
int max(int a, int b);
int forAll(int* liczby, int elementCount, f wybranaFunkcja);

int main() {
	
	int functionId, elementCount, wynik, i, j, v;
	int* liczby;

	f wybor[3];
	f suma = sum;
	f miniumum = min;
	f maksimum = max;
	
	wybor[0] = miniumum;
	wybor[1] = maksimum;
	wybor[2] = suma;

	printf("\n");
	printf("Wybierz rodzaj dzialania:\n1 = minimum\n2 = maksimum\n3 = suma\n");
	scanf("%d", &functionId);

	if(functionId > 4 || functionId < 0 ) {
		printf("Nie ma takiej funkcji");
		return 1;
	}
	printf("Wybrales = %d\n", functionId);

	
	printf("Ile liczb podasz?\n");
	scanf("%d", &elementCount);

	if(elementCount <= 1){
		printf("Podales za malo liczb");
		return 2;
	}
	liczby = calloc(elementCount, sizeof(int));
	
	printf("Podaj je\n");
	for(i = 0; i < elementCount; i++){
		scanf("%d", &liczby[i]);
	}

	
	v = liczby[0];
	for(j = 1; j < elementCount; j++){
		v = wybor[functionId - 1](v, liczby[j]);
	}
	printf("V = %d\n",v);
	
	wynik = forAll(liczby, elementCount, wybor[functionId -1]);
	printf("Wynik = %d\n", wynik);

	free(liczby);
	printf("\n");
	return 0;
}

int sum(int a, int b){
	return a + b;
}

int min(int a, int b){

	if(a < b){return a;}
	return b;
}

int max(int a, int b){
	if(a > b) {return a;}
	return b;
}

int forAll(int* liczby, int elementCount, f wybranaFunkcja){

	int v, j;
	v = liczby[0];
	
	for(j = 1; j < elementCount; j++){
		v = wybranaFunkcja(v, liczby[j]);
	}
	
	return v;
}
