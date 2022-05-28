#include <stdio.h>
#include <stdlib.h>

int main(){

	int liczba;
	int ilosc;
	int i;

	printf("Ile liczb chcesz podac?\n");
	scanf("%d", &ilosc);

	printf("Podaj te liczby\n");
	for(i = 0; i < ilosc; i++){
		if(scanf("%d", &liczba) == 0){
		       printf("Nie podales liczby tylko co innego\n");
		       getchar();
		}
	
		else{
			printf("Twoja liczba = %d\n", liczba);	
		}
	}
	return 0; 
}
