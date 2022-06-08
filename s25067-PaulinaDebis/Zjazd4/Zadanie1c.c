#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
	int h=0;
	int i=0;
	int j=0;
	int k=0;
	int p=0;

	printf("Podaj proszę wysokość choinki: \n");
	scanf("%d",&h);
	for (i=0; i<h; i++) {
		for (j=0; j<h-i; j++) {
			printf(" ");
		}
		for (k=0; k<i*2+1;k++) {
			printf("*");
		}
		printf(" ");
		printf("\n");
	}

	for (p=0; p<h/2+1;p++) {
		printf(" ");
	}
	printf("  #  ");
	printf("\n");

return 0;
}
