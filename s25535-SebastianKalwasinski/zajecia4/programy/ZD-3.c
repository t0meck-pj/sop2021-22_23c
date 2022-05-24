#include <stdio.h>

int fib(int);

int main() {

	int iteracje, i;
       	int a = 0;
	int b = 1;
	int c = a + b;

	printf("\nIle pozycji wydrukowac?\n");
	scanf("%d", &iteracje);
	
	printf("Fibonacci iteracyjnie:   ");
	for(i = 0; i < iteracje; i++){
		printf("%d ", a);
	       	a = b;
		b = c;
		c = a + b;
	}
	
	printf("\nFibonacci rekurencyjnie: ");
	for(i = 0; i < iteracje; i++) {
		printf("%d ",fib(i));
	}
	printf("\n\n");
	return 0;
}

int fib(int i) {
	
	switch (i) {
		case 0: return 0;
		case 1: return 1;
		default:return (fib(i - 1) + fib(i - 2));
	}
}
