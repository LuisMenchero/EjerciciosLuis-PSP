// Cuarto ejercicio
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
  pid_t pid, pid2, pid3, pid4;

  int acumulado = getpid();
  pid = fork();

  if (pid == 0) // P2
  {
    pid2 = fork();

    if (pid2 == 0) // P5
    {
      printf("p5\n");
    }
    else // P2
    {
      wait(NULL);
      printf("p2\n");
    }
    if (getpid() % 2 == 0)
    {
      printf("%d \n", acumulado + 10);
    }
    else
    {
      printf("%d \n", acumulado - 100);
    }
  }
  else // P1
  {
    pid3 = fork();

    if (pid3 == 0)
    { // P3
      pid4 = fork();

      if (pid4 == 0)
      { // P4
        printf("p4\n");
      }
      else
      { // P3
        wait(NULL);
        printf("p3 \n");
      }
      if (getpid() % 2 == 0)
      {
        printf("%d \n", acumulado + 10);
      }
      else
      {
        printf("%d \n", acumulado - 100);
      }
    }
    else
    { // P1
      wait(NULL);
      printf("p1 \n");
    }
  }

  exit(0);
}