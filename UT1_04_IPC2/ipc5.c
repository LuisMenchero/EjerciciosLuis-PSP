#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    int fd1[2], fd3[2];
    int num1, num2;
    char buffer[200];

    pipe(fd1);
    pipe(fd3);

    pid_t pid1 = fork();

    if (pid1 == 0)
    {
        // P2
        // leer pipe 1
        close(fd1[1]);
        int numRecibido, resulSum = 0;
        while (read(fd1[0], &buffer, sizeof(buffer)))
        {
            numRecibido = atoi(buffer);
            resulSum += numRecibido;
        }
        close(fd1[0]);

        // escribir en pipe 3
        close(fd3[0]);
        write(fd3[1], &resulSum, sizeof(resulSum));
        close(fd3[1]);
    }
    else
    {
        int fd2[2], fd4[2];

        pipe(fd2);
        pipe(fd4);

        pid_t pid2 = fork();

        if (pid2 == 0)
        {
            // P3
            // leer pipe 2
            close(fd2[1]);
            int numRecibido, resulMulti = 1;
            while (read(fd2[0], &buffer, sizeof(buffer)))
            {
                numRecibido = atoi(buffer);
                resulMulti *= numRecibido;
            }
            close(fd2[0]);

            // escribir en pipe 4
            close(fd4[0]);
            write(fd4[1], &resulMulti, sizeof(resulMulti));
            close(fd4[1]);
        }
        else
        {
            // P1

            // Numeros
            printf("Introduce el primer número: ");
            scanf("%d", &num1);
            printf("Introduce el segundo número: ");
            scanf("%d", &num2);
            int nums[] = {num1, num2};
            int tamañoArray = sizeof(nums) / sizeof(nums[0]);

            // Enviarselo a P2 desde pipe 1
            close(fd1[0]);

            for (int i = 0; i < tamañoArray; i++)
            {
                sprintf(buffer, "%d", nums[i]);
                write(fd1[1], buffer, sizeof(buffer));
            }
            close(fd1[1]);

            // Enviarselo a P3 desde pipe 2
            close(fd2[0]);

            for (int i = 0; i < tamañoArray; i++)
            {
                sprintf(buffer, "%d", nums[i]);
                write(fd2[1], buffer, sizeof(buffer));
            }
            close(fd2[1]);

            wait(NULL);
            wait(NULL);

            // leer pipe 3
            close(fd3[1]);
            int resulSum;
            read(fd3[0], &resulSum, sizeof(resulSum));
            printf("Resultado suma: %d \n", resulSum);
            close(fd3[0]);

            // leer pipe 4
            close(fd4[1]);
            int resulMulti;
            read(fd4[0], &resulMulti, sizeof(resulMulti));
            printf("Resultado multiplicación: %d \n", resulMulti);
            close(fd4[0]);
        }
    }
}
