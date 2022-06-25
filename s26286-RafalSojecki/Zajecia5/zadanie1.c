/*Napisz program, który
przedstawi swój numer PID, oraz PPID
po wypisaniu, będzie czekał na standardowym wejściu na dane od użytkownika.
Uruchom program - nic nie podawaj na wejściu (program powinien czekać
w nieskończoność).Uruchom nowy terminal. W nim za pomocą komendy kill zamknij
 ten program korzystając z PID wypisanego przez niego na początku.
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    int data = 0;
    printf("PID:%i\n", getpid());
    printf("PIDD:%i\n", getppid());
    scanf("%d", &data);
    return 0;
}
