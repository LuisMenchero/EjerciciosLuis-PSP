#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void main()
{
    int fd[2];
    time_t hora;
    char *fecha;
    time(&hora);
    fecha = ctime(&hora);

    pipe(fd);

    pid_t pid = fork();

    if (pid == 0)
    {
        close(fd[1]);

        char *recibido;
        read(fd[0], &recibido, sizeof(recibido));

        printf("Soy el proceso hijo con pid %d \n", getpid());
        printf("Fecha/hora: %s \n", recibido);
        close(fd[0]);
    }
    else
    {
        close(fd[0]);

        write(fd[1], &fecha, sizeof(fecha));

        close(fd[1]);

        wait(NULL);
    }
}