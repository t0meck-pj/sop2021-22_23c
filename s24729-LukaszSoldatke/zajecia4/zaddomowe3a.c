#include <stdio.h>
#include <stdlib.h>

int fibonacci(int number_of_elements) {
	if (number_of_elements <= 1) {
		return number_of_elements;
	} else {
		return fibonacci(number_of_elements - 1) + fibonacci(number_of_elements - 2);
	}
}

int main() {
	int number_of_elements, i = 0;

	printf("Podaj ilu elementowy ciag Fibonacciego chcesz wyswietlic rekurencyjnie: ");
	scanf("%d", &number_of_elements);
	printf("\n");

	for (i = 0; i < number_of_elements; i++) {
		printf("%d ", fibonacci(i));
	}
	printf("\n");

	return 0;
}
