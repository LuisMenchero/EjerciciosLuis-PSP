#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    int fd1[2], fd2[2];

    pipe(fd1);
    pipe(fd2);

    int numAl;
    time_t t;
    srand((unsigned)time(&t));
    // Generamos numero aleatorio entre 1 y 10
    numAl = rand() % 10;


    pid_t pid = fork();

    if (pid == 0)
    {
        close(fd1[1]);

        int numAl;
        read(fd1[0], &numAl, sizeof(numAl));
        int resulFactorial = 1;

        for (int i = 1; i <= numAl; i++)
        {
            resulFactorial *= i;
        }
        close(fd1[0]);

        close(fd2[0]);
        write(fd2[1], &resulFactorial, sizeof(resulFactorial));
        close(fd2[1]);
    }
    else
    {
        close(fd1[0]);
        write(fd1[1], &numAl, sizeof(numAl));
        printf("El proceso padre genera el numero %d en el pipe1. \n", numAl);
        close(fd1[1]);


        wait(NULL);

        close(fd2[1]);
        int resulFactorial;
        read(fd2[0], &resulFactorial, sizeof(resulFactorial));
        printf("El factorial calculado por el proceso hijo: %d != %d. \n", numAl, resulFactorial);
        close(fd2[0]);
    }
}
