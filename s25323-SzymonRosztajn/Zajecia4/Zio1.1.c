#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    
    char buff[255];
    char *file_name=argv[1];
    FILE *fp=fopen(file_name,"r");

    while(fscanf(fp, "%s", buff)!=EOF){  
        printf("%s ", buff );  
    }  
    fclose(fp);  

    return 0;
}
