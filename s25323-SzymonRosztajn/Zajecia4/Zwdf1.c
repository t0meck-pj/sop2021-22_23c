#include <stdio.h>
#include <stdlib.h>

typedef int (* f) (int, int);

void clear_screen(){
    int i;
    for (i = 0; i < 50; i++){
        printf("\n\n\n");
    }
}


int max(int first, int second) {
    return first > second ? first : second;
}

int min(int first, int second) {
    return first < second ? first : second;
}

int sum(int first, int second) {
    return first+second;
}

void get_function_id(int *f_id){
    clear_screen();
    printf("Witaj, w kalkulatorze, oto mozliwe wybory: \n");
    printf("0 - Suma\n");
    printf("1 - Maksimum\n");
    printf("2 - Minimum\n");
    printf("\n Twoj wybor: ");
    scanf("%d",f_id);
}

void get_iterations(int *it){
    clear_screen();
    printf("Okej zatem, ile liczb chcesz podac? \n");
    scanf("%d",it);
}



int main(){

    f sum_function=sum;
    f max_function=max;
    f min_function=min;
    f table[3];

    int* table_user_numbers;
    int function_id;
    int iterations;
    int index;
    int index2;
    int current_value;

    table[0]=sum_function;
    table[1]=max_function;
    table[2]=min_function;

    get_function_id(&function_id);
    get_iterations(&iterations);

    table_user_numbers=malloc(10000 * sizeof(int));

    for(index=0;index<iterations;index++){
        printf("Liczba nr: %d - ",index+1);
        scanf("%d",&table_user_numbers[index]);
    }

    current_value=table_user_numbers[0];

    for (index2=1;index2<iterations;index2++){
        current_value=table[function_id](current_value,table_user_numbers[index2]);
    }

    printf("\n Wynik: %d \n",current_value);
    

    free(table_user_numbers);
    return 0;

}
