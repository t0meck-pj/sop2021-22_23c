#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int size;
	char* filepath = argv[1];
	FILE* file = fopen(filepath, "r");

	if (file != NULL) {
		char character = fgetc(file);
		int offset = 16, i = 1;

		fscanf(file, "%d", &size);

		printf("Zawartosc pliku (HEX):\n");
		printf("%x: ", offset);
		while (character != EOF) {
			offset = offset + 16;

			printf("%x ", character);
			if (i % 16 == 0) {
				printf("\n");
				printf("%x: ", offset);
			}

			character = fgetc(file);
			i++;
		}
		printf("\n");
	} else {
		printf("Nie mozna otworzyc pliku\n");
		return 1;
	}

	fclose(file);
	printf("\n");
	file = fopen(filepath, "r");

	if (file != NULL) {
                char character = fgetc(file);
                int offset = 16, i = 1;

                fscanf(file, "%d", &size);

                printf("Zawartosc pliku:\n");
                printf("%x: ", offset);
                while (character != EOF) {
                        offset = offset + 16;

                        printf("%c ", character);
                        if (i % 16 == 0) {
                                printf("\n");
                                printf("%x: ", offset);
                        }

                        character = fgetc(file);
                        i++;
                }
	} else {
                printf("Nie mozna otworzyc pliku\n");
                return 1;
        }

	printf("\n");
        fclose(file);

	return 0;
}
