#include <stdio.h>

int main() 
{
    int sum = 0;
    int input = 0;

    while(scanf("%d\n", &input) > 0)
    {
        sum += input;
    }

    printf("%d\n", sum);
    return sum;
}
