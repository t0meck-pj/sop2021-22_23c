#include <stdio.h>

int rekurencja(int n);

int main() {
    int n,i, wybor;
    int fib = 0;
    int fib1 = 1;
    int fib2 = 1;

    printf("(1) Rekurencja\n(2) Iteracja\n");
    scanf("%d", &wybor);
    printf("Podaj liczbe ciagu: \n");
    scanf("%d", &n);

    switch(wybor)
    {
    case 1:
        printf("%d\n", rekurencja(n));
    case 2:
        if (n == 0)
        {
            return 0;
        }
        else if (n <= 2)
        {
            return 1;
        }
        else
        {
            for (i = 1; i < n; i++)
            {
                fib = fib1;
                fib1 = fib2;
                fib2 = fib + fib1;
            }

            printf("%d\n", fib2);
        }
   }
   return 0;
}

int rekurencja(int n) {
    if (n == 0)
    {
        return 0;
    }
    else if (n <= 2)
    {
        return 1;
    }
    else
    {
        return rekurencja(n-1) + rekurencja(n-2);
    }
}
