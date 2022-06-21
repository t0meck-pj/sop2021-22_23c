#include <stdio.h>
#include <stdlib.h>

int main() {
	int number_of_elements, number1 = 0, number2 = 1, sum = 0, i = 0;

	printf("Podaj ilu elementowy ciag Fibonacciego chcesz wyswietlic iteracyjnie: ");
	scanf("%d", &number_of_elements);
	printf("\n");

	for (i = 0; i < number_of_elements; i++) {
		printf("%d ", number1);
		sum = number1 + number2;
		number1 = number2;
		number2 = sum;
	}
	printf("\n");

	return 0;
}
