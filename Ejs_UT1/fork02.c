// Segundo ejercicio
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    pid_t pid, pid_hijo;

    pid = fork();

    if (pid == 0) {
        printf("Luis \n");
    } else {
        pid_hijo = wait(NULL);
        printf("Mi hijo tiene PID es %d \n",pid_hijo);
        printf("Mi PID es %d \n",getpid());
    }
   exit(0);
}