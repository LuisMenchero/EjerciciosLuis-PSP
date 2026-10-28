#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    int fd[2];
    char buffer[200];
    pipe(fd);

    pid_t pid = fork();

    if (pid == 0)
    {
        close(fd[0]);

        int numAleatorio1, numAleatorio2;
        time_t t;
        srand((unsigned)time(&t));
        // Generamos numero aleatorio entre 1 y 50
        numAleatorio1 = rand() % 50;
        numAleatorio2 = rand() % 50;

        int numeros[2];
        numeros[0] = numAleatorio1;
        numeros[1] = numAleatorio2;

        int tamañoArray = sizeof(numeros) / sizeof(numeros[0]);

        for (int i = 0; i < 2; i++)
        {
            sprintf(buffer, "%d", numeros[i]);
            write(fd[1], buffer, sizeof(buffer));
        }

        sprintf(buffer, "+");
        write(fd[1], buffer, sizeof(buffer));

        close(fd[1]);
    }
    else
    {
        close(fd[1]);

        int num1Recibido, num2Recibido, resultadoSuma = 0, resultadoResta = 0, resultadoMultiplicacion = 0, resultadoDivision = 0;
        bool todosLosDatosRecibidos = false;

        int i = 0;
        while (read(fd[0], buffer, sizeof(buffer)) > 0)
        {
            if (!todosLosDatosRecibidos)
            {
                if (strcmp(buffer, "+") == 0)
                {
                    printf("Recibido carácter +\n");
                    todosLosDatosRecibidos = true;
                }
                else
                {
                    int num = atoi(buffer);
                    printf("Numero %d recibido: %d\n", i + 1, num);
                    if (i == 0)
                    {
                        num1Recibido = num;
                    }
                    else
                    {
                        num2Recibido = num;
                    }
                    i++;
                }
            }
        }
        resultadoSuma = num1Recibido + num2Recibido;
        resultadoResta = num1Recibido - num2Recibido;
        resultadoMultiplicacion = num1Recibido * num2Recibido;
        resultadoDivision = num1Recibido / num2Recibido;

        printf("%d + %d = %d\n", num1Recibido, num2Recibido, resultadoSuma);
        printf("%d - %d = %d\n", num1Recibido, num2Recibido, resultadoResta);
        printf("%d * %d = %d\n", num1Recibido, num2Recibido, resultadoMultiplicacion);
        printf("%d / %d = %d\n", num1Recibido, num2Recibido, resultadoDivision);
        close(fd[0]);
        wait(NULL);
    }
}
