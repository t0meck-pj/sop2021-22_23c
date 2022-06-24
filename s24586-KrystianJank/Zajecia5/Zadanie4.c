#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[]){
    
     pid_t pid=fork();
     int poczatek,koniec=100,licznik=0;
     for(poczatek=0;poczatek<=koniec;poczatek++){
     printf("%d Ile juz jest dzieci \n",licznik++);
     
     if(pid == 0){
     sleep(1);
     return (licznik);
}
    }
return 0;
sleep(15);
}