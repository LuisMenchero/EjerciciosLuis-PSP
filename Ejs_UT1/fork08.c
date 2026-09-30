// Octavo ejercicio
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
    pid_t pid1, pid2;
    printf("AAA \n");
    pid1 = fork();
    if (pid1 == 0)
    {
        printf("BBB \n");
    }
    else
    {
        pid2 = fork();
        if (pid2 == 0)
        {
            printf("CCC \n");
        }
        else
        {
            wait(NULL);
            wait(NULL);
        }
    }
    exit(0);
}