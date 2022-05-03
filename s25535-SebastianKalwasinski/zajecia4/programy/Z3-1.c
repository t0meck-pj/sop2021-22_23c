#include <stdio.h>
#include <stdlib.h>


typedef int (*f)(int, int);
int sum(int a, int b);
int min(int a, int b);
int max(int a, int b);

int main() {
	
	int functionld, elementCount, i, j, v;
	int* liczby;

	f wybor[3];
	f suma = sum;
	f miniumum = min;
	f makimum = max;
	
	wybor[0] = miniumum;
	wybor[1] = makimum;
	wybor[2] = suma;

	printf("\n");
	printf("Wybierz rodzaj dzialania:\n1 = minimum\n2 = maksimum\n3 = suma\n");
	scanf("%d", &functionld);

	if(functionld > 4 || functionld < 0 ) {
		printf("Nie ma takiej funkcji");
		return 1;
	}
	printf("Wybrales = %d\n", functionld);

	
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
		v = wybor[functionld - 1](v, liczby[j]);
	}
	printf("V = %d\n",v);

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
