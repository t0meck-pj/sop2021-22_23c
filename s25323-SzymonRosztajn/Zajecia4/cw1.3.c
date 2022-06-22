#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int index = 0;
	int height = 0;
    height = atoi(argv[1]);

	for (index = 0; index < height; index++) {

        int index2 = 0;
		int spaces = height - index;
        int stars = index * 2 + 1;

		for (index2 = 0; index2 < spaces; index2++){printf(" ");}
		for (index2 = 0; index2 < stars; index2++){printf("*");}

		printf("\n");
	}
	for (index = 0; index < height; index++) {
		printf(" ");
	}
	printf("*\n");

	return 0;
}
