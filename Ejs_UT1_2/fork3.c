// Primer ejercicio
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
  pid_t pid, pid2, pid3, pid4, pid5;

  pid = fork();

  if (pid == 0) { // P2
    pid2 = fork();
    if (pid2 == 0) { // P3
      pid3 = fork();
      if (pid3 == 0) { // P5
        printf("P5 \n");

        printf("Mi PID es: %d \n",getpid());
        printf("El PID de mi abuelo es: %d \n",);

      } else { // P3
        wait(NULL);
        printf("P3 \n");




      }
    } else { // P2
      pid4 = fork();
      if (pid4 == 0) { // P4
        pid5 = fork();
        if (pid5 == 0) { // P6
          printf("P6 \n");

          printf("Mi PID es: %d \n",getpid());
          printf("El PID de mi abuelo es: %d \n",pid);


        } else { // P4
          wait(NULL);
          printf("P4 \n");



        }
      } else { // P2
        wait(NULL);
        wait(NULL);
        printf("P2 \n");
        printf("Mi PID es: %d \n",getpid());
      }
    }
  } else { // P1
    wait(NULL);
    printf("P1 \n");
    printf("Mi PID es: %d \n",getpid());
  }

  exit(0);
}