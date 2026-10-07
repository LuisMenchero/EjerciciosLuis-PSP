#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    int fd[2];
    int numero;

    pipe(fd);

    pid_t pid = fork();

    if (pid == 0)
    {
        // HIJO: solo lee
        close(fd[1]);

        int recibido;

        for (int i = 0; i < 10; i++)
        {
            read(fd[0], &recibido, sizeof(recibido));
            
            printf("HIJO: He recibido %d\n", recibido);
        }

        close(fd[0]);
    }
    else
    {
        // PADRE: solo escribe
        close(fd[0]);

        for (int i = 0; i < 10; i++)
        {
            numero = i;
            
            write(fd[1], &numero, sizeof(numero));

            printf("PADRE: He enviado %d\n", numero);
        }

        close(fd[1]);

        wait(NULL);
    }
}