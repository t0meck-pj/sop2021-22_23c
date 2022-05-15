#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int i = 0;
	int j = 0;
	int gwiazdki = 0;
	int spacje = 0;
	int wysokosc = 0;
	
	if(argc == 1){
		printf("Nalezy podac wysokosc choinki!\n");
		return 1;
	}
	
	wysokosc = atoi(argv[1]);
	for (i = 0; i < wysokosc; i++) {
		spacje = wysokosc - i;
		for (j = 0; j < spacje; j++) {
			printf(" ");
		}
		gwiazdki = i * 2 + 1;
		for (j = 0; j < gwiazdki; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < wysokosc; i++) {
		printf(" ");
	}
	printf("*\n");

	return 0;
}

