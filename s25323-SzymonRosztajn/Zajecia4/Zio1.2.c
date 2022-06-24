#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int index;
    int index2;
	int size;
	int* numbers;
	char* file_name = argv[1];
    FILE* fp;
	fp=fopen(file_name,"r");

	if(fp){
		fscanf(fp, "%d", &size);
		numbers=malloc(size);

		for(index = 0; index < size; index++) {
			fscanf(fp, "%d", &numbers[index]);
		}
		for(index2 = size - 1; index2 >= 0; index2--) {
			printf("%d ", numbers[index2]);
		}
        printf("\n");
        free(numbers);
        fclose(fp);
	}else{
		return 2;
	}


	return 0;
}
