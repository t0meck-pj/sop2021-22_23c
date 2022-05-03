#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

        int i;

	if(argc == 1){
		printf("Nie tykaj nieswojej pamieci\n");
		printf("Musisz podac przynajmniej jeden argument\n");
		return 1;
	}

	i = atoi(argv[1]);
	printf("Moj argument = %d\n", i);
	
	i = i + 1;
	
	printf("Moj argument + 1 = %d\n", i);

	return 0;
}
