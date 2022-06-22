#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        int i, j;
        int wiersze = atoi(argv[1]);
        printf("Wiersze: %d\n", wiersze);

        for(i = 1; i <= wiersze; i++)
        {
            for (j = 0; j < wiersze - i; j++)
	    {
                printf(" ");
            }

            for (j = 0; j < i*2-1 ; j++)
	    {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
