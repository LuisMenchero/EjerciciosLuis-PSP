#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int fd[2];
    char buffer[200];
    pipe(fd);

    pid_t pid = fork();

    if (pid == 0)
    {
        close(fd[1]);

        int num;
        int resultado = 0;
        bool sumaTerminada = false;

        while (read(fd[0], buffer, sizeof(buffer)) > 0)
        {
            if (!sumaTerminada)
            {
                if (strcmp(buffer, "+") == 0)
                {
                    printf("Recibido carácter +\n");
                    sumaTerminada = true;
                }
                else
                {
                    num = atoi(buffer);
                    printf("Numero a sumar: %d\n", num);
                    resultado += num;
                }
            }
        }

        printf("La suma total es igual a: %d\n", resultado);

        close(fd[0]);
    }
    else
    {
        close(fd[0]);

        int numeros[] = {25, 18, 67};
        int tamañoArray = sizeof(numeros) / sizeof(numeros[0]);

        for (int i = 0; i < tamañoArray; i++)
        {
            sprintf(buffer, "%d", numeros[i]);
            write(fd[1], buffer, sizeof(buffer));
        }

        sprintf(buffer, "+");
        write(fd[1], buffer, sizeof(buffer));

        close(fd[1]);
        wait(NULL);
    }
}
