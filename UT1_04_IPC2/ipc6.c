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
        // leer pipe 3
        close(fd3[1]);
        int numRecibido, media = 0, numMax = 0;
        while (read(fd3[0], &buffer, sizeof(buffer)))
        {
            numRecibido = atoi(buffer);

            if (numMax < numRecibido)
            {
                numMax = numRecibido;
            }
            
            media += numRecibido;
        }
        media /= 10;

        close(fd3[0]);

        // escribir en pipe 1
        close(fd1[0]);
        write(fd1[1], &media, sizeof(media));
        write(fd1[1], &numMax, sizeof(numMax));
        close(fd1[1]);
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
            int numRecibido, numAprobados = 0, numSuspensos = 0;
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
            // Pedir 10 notas
            int numNotasIntroducidas = 0, notaIntroducida;
            double notas[10];
            int tamañoArray = sizeof(notas) / sizeof(notas[0]);
            do{
                printf("Introduce una nota número %d: ",numNotasIntroducidas+1);
                scanf("%d", &notaIntroducida);
                if (notaIntroducida >= 0 && notaIntroducida <= 10)
                {
                    notas[numNotasIntroducidas] = notaIntroducida;
                    numNotasIntroducidas++;
                } else {
                    printf("Nota no válida \n");
                }
            }while(numNotasIntroducidas != 10);

            // Enviar calificaciones a P2 y P3
            close(fd3[0]);
            close(fd4[0]);
            for (int i = 0; i < tamañoArray; i++)
            {
                sprintf(buffer, "%d", notas[i]);
                write(fd3[1], buffer, sizeof(buffer));
                write(fd4[1], buffer, sizeof(buffer));
            }
            close(fd3[1]);
            close(fd4[1]);

            wait(NULL);
            wait(NULL);
            /*
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
            */
        }
    }
}
