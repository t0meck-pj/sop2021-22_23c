#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int funkcja(int a){
int i;
	for(i = 2; i<= a/2; i++)
if ((a%i) == 0)
return 0;
return 1;
}


int main(int argc,char **argv)
{
       int b,i;
       int s=0;
      b=atoi(argv[1]);
      if (fork()==0){
      for ( i=2;i<b;i++){
        if(funkcja(i)) printf("%d  \n",i);
}
        printf("\n");

printf("\n");
}else{
for( i=0;i<b;i++){
s=s + i;

}
printf("suma wynosi:%d\n",s);
printf("Liczby pierwsze:\n");
wait(NULL);

}
        return 0;
}
