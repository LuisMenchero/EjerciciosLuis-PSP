#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void main()
{
    int fd[2];
    char buffer[200];
    pipe(fd);

    pid_t pid = fork();


    if (pid == 0)
    {
        close(fd[1]);

        char *recibido;
        int num, resultado = 0;
        while (read(fd[0], &recibido, sizeof(recibido)))
        {
            
            num = atoi(recibido);

            printf("Soy el proceso hijo con pid %d \n", getpid());
            printf("Numero a sumar: %d \n", num);
            resultado += num;
        }
        
        
        
        close(fd[0]);
    }
    else
    {
        close(fd[0]);
        int numeros[] = {25,18,67};
        int i = 0;

        char *valorEscrito;
        char suma = '+';

        do {
            if (i > sizeof(numeros))
            {
                write(fd[1], &numeros[i], sizeof(numeros[i]));
                valorEscrito = sprintf(buffer,"%s\n",numeros[i]);
                i++;
            } else {
                write(fd[1], &suma, sizeof(suma));
            }
        }while (strcmp(valorEscrito, "+") != 0);
        
        

        close(fd[1]);

        wait(NULL);
    }
}