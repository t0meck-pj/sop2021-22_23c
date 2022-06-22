#include <stdio.h>
#include <stdlib.h>

int main() {
    int repetitions;
    int result=0;
    int i;

    printf("Enter how many numbers do you want to enter: ");
    scanf("%d",&repetitions);

    for (i = 0; i < repetitions; i++){
        int temporary_number=0;
        printf("%d: ",i+1);
        scanf("%d",&temporary_number);

        result+=temporary_number;
    }
    
    return result;
}
