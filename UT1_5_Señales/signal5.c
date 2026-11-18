#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>



void funcion_señal(int signum)
{
   
}

int main()
{
    pid_t pid;

    pid = fork();

    if (pid == 0) // p2
    {
        
    } else {
        pid_t pid2;

        pid2 = fork();

        if (pid2 == 0) // p3
        {
            
        } else { // p1
            int num;
            printf("Introduce número: ");
            scanf("%d", &num);
        }
    }
    

}