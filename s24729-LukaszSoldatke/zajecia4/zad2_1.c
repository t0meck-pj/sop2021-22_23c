#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int size, i, number;
	char* filepath = argv[1];
	FILE* file = fopen(filepath, "r");

	if (file != NULL) {
		fscanf(file, "%d", &size);

		printf("Zawartosc pliku:\n");
		for (i = 0; i < size; i++) {
			fscanf(file, "%d", &number);
			printf("%d ", number);
		}
		printf("\n");
	} else {
		printf("Nie mozna otworzyc pliku\n");
		return 1;
	}

	fclose(file);

	return 0;
}
