// Primer ejercicio
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid;

  pid = fork();
  pid = fork();

  if (pid == 0 ) {        
  } else { 
    wait(NULL);

  }

  if (getpid() % 2 == 0) {
    printf("Mi PID es: %d \n",getpid());
    printf("El PID de mi padre es: %d \n",getppid());
  } else {
    printf("Mi PID es: %d \n",getpid());
  }

   exit(0);
}