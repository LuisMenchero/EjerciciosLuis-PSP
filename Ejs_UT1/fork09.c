// Noveno ejercicio
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
    pid_t pid1, pid2, pid3, pid4;

    pid1 = fork();
    if (pid1 == 0)
    {
        sleep(5);
        printf("P2 \n");
        
    }
    else
    {
        pid2 = fork();
        if (pid2 == 0)
        {
            sleep(2);
            printf("P3 \n");
        }
        else
        {
            pid3 = fork();
            if (pid3 == 0)
            {
                sleep(4);
                printf("P4 \n");
            }
            else
            {
                wait(NULL);
                wait(NULL);
                wait(NULL);
                printf("P1 \n");
            }
        }
    }
    exit(0);
}