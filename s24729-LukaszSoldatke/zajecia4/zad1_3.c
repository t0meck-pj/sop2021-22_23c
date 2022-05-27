#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	char* height_str = argv[1];
	int height = atoi(height_str), i, j, k;

	for (i = 1; i <= height; i++) {
		for (j = height - i; j > 0; j--) {
			printf(" ");
		}
		for (k = 1; k <= i; k++) {
			printf("* ");
		}
		printf("\n");
	}

	return 0;
}
