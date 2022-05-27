#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int size, i;
	int* numbers;
	char* filepath = argv[1];
	FILE* file = fopen(filepath, "r");

	if (file != NULL) {
		fscanf(file, "%d", &size);
		numbers = calloc(size, sizeof(int));

		for (i = 0; i < size; i++) {
			fscanf(file, "%d", &numbers[i]);
		}

		printf("Zawartosc pliku:\n");
		for (i = size - 1; i >= 0; i--) {
			printf("%d ", numbers[i]);
		}
		printf("\n");
	} else {
		printf("Nie mozna otworzyc pliku\n");
		return 1;
	}

	free(numbers);
	fclose(file);

	return 0;
}
