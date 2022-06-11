#include <stdio.h>

int main(){
	int x=0;
	int y=0;
	int wynik=0;
        printf("Podaj dwie liczby:\n");
        scanf("%d %d", &x, &y);
		
	int suma (int x, int y) 
	{
        	wynik=x+y;
        	return wynik;
	}

suma(x,y);
printf("Twój wynik: %d\n",wynik);

return 0;
}


