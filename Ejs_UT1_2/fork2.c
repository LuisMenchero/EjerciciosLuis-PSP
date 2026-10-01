// Primer ejercicio
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
  pid_t pid, pid2, pid3;

  pid = fork();

  if (pid == 0)
  {
    pid2 = fork();

    if (pid2 == 0)
    {
      pid3 = fork();

      if (pid3 == 0)
      {
        printf("Soy 4 \n");
      }
      else
      {
        wait(NULL);
        printf("Soy 3 \n");
      }
    }
    else
    {
      wait(NULL);
      printf("Soy 2 \n");
    }
  }
  else
  {
    wait(NULL);
    printf("Soy 1 \n");
  }

  printf("Mi PID es: %d \n", getpid());
  printf("El PID de mi padre es: %d \n", getppid());
  printf("Mi PID y el de mi padre suman %d \n", getpid() + getppid());

  exit(0);
}