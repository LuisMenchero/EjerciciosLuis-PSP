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
        sleep(10);
        printf("Despierto\n");
    } else {
        pid = fork();
        if (pid == 0) {
            printf("-  PROCESO 3 - \n");
            printf("Mi PID es: %d \n", getpid());
            printf("El PID de mi padre es: %d \n", getppid());
        } else {
            wait(NULL);
            wait(NULL);
        }
    }
    
    exit(0);
}