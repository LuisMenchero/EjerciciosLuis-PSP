// Décimo ejercicio
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
    pid_t pid1, pid2;
    int resultado;
  
    pid1 = fork();
    if (pid1 == 0) {
       printf("P2 %d \n", getpid());
      for (int i = 0 ; i <100 ; i++) {
        resultado = i + 1;
        printf(" %d + 1 = %d \n", i, resultado);
      }
    } else {
        pid2 = fork();
        if (pid2 == 0) {
          sleep(5);
          printf("P3 %d \n", getpid());
      for (int i = 100 ; i <200 ; i++) {
        resultado = i + 1;
        printf(" %d + 1 = %d \n", i, resultado);
      }
        } else {
          wait(NULL);
          wait(NULL);
          printf("Todos los cálculos han finalizado. \n");
        }
    }
    exit(0);
}
