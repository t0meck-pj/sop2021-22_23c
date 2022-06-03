#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* load_to_table(char* path_name);
void print_hex(char* table);
void print_values(char* table);


int main(int argc, char** argv) {

	char *file_name=argv[1];
	char *numbers=load_to_table(file_name);
	char *temporary_table=malloc(sizeof(char));
	int actual_location;
	int multipler=-1;
	int i;


	for (i = 0; i < 512; i++){
		actual_location=i-(16*multipler)-1;
		temporary_table[actual_location]=numbers[i];

		if (i%16==0){
			multipler+=1;
			printf("%02X    ",i);
			print_hex(temporary_table);
			print_values(temporary_table);
			printf("\n");
		}
		
	}
	

	free(temporary_table);
	free(numbers);
	return 0;
}

void print_hex(char* table){
	int index;

	for (index = 0; index < 16; index++){
		printf(" %02X ",table[index]);
	}

}

void print_values(char* table){
	int index;

	printf(" ");


	for (index = 0; index < 16; index++){
		printf("%c",table[index]);
	}
}

char* load_to_table(char* path_name){

	FILE *file=fopen(path_name,"r");
	unsigned char character=0;
	char *numbers=malloc(sizeof(char));
	int counter=0;

	while(!feof(file)){
		character=getc(file);
		if (character=='\n' || character=='\t'){
			continue;
		}

		numbers[counter]=character;
		counter+=1;
	}

	return numbers;

}
