// Segundo ejercicio
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        sleep(3);
    } else {
        pid = fork();
        if (pid == 0) {
            sleep(1);
        } else {
            wait(NULL);
            wait(NULL);
            printf("Todos mis hijos han terminado \n");
        }
    }

    printf("Mi PID es: %d \n", getpid());
    printf("El PID de mi padre es: %d \n", getppid());

    exit(0);
}