#include <stdio.h>
#include <stdlib.h>

int main() {
	int number_count = 0, result, i;
	int *numbers = calloc(number_count, sizeof(int));

	printf("Podaj ile liczb chcesz dodac: ");
	scanf("%d", &number_count);

	for (i = 0; i < number_count; i++) {
		printf("Podaj liczbe: ");
        	scanf("%d", &numbers[i]);
        	result = result + numbers[i];
	}

	printf("Wynik: %d\n", result);
	free(numbers);

	return 0;
}
