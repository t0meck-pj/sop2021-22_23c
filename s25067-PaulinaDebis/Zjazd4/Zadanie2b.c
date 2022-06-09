#include <stdio.h>

int main() {

	

        int tablica[50];
        int i=0;

        FILE* plik;
        plik= fopen("liczby", "r");

        while (fscanf(plik, "%d", &tablica[i]) != EOF) {
                i++;
        }
        fclose(plik);

        tablica[i] = '\0';

        for (tablica[i]=='\0'; i>0; i--) {
                printf("%d\n", tablica[i-1]);
        }

return 0;
}

