#include <stdio.h>
#include <stdbool.h>

int main() {
        int number,
            sum = 0,
            value;

        printf("Jeśli chcesz zakończyć program wpisz: [dowolny znak typu char]\n");

        while(true) {
            printf("Podaj liczbe: ");
            value = scanf("%d", &number);

            if (value == 0) break;

            sum += number;
        }

        return printf("Wynik to: %d \n", sum);
}
