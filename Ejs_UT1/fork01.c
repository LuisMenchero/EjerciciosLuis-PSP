// Primer ejercicio
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_hijo;

  pid = fork();

  if (pid == 0 ) {        
    printf("Soy el proceso HIJO \n");
    printf("Mi PID es: %d \n",getpid());
    printf("El PID de mi padre es: %d \n",getppid());
  } else { 
    pid_hijo = wait(NULL);
    printf("Soy el proceso PADRE\n"); 
    printf("Mi PID es: %d \n",getpid());
    printf("Mi hijo tenia el PID: %d \n",pid);
    printf("El proceso hijo ha terminado \n");
  }
   exit(0);
}