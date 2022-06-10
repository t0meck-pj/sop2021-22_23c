#include <stdio.h>

long int fibo_recursive(long int i){
    if(i<2){
        return i;
    }
    else{
        return fibo_recursive(i-1)+fibo_recursive(i-2);
    }
}

long int fibo_iterative(long int i){
    long int x=0;
    long int y=1;
    long int temporary;
    int index;

    for (index = 0; index < i; index++){
        temporary=x+y;
        x=y;
        y=temporary;    
    }
    
    return x;
}

int main(){

    long int number=50;

    printf("%ld",fibo_iterative(number));

    return 0;
}
