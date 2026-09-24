// Segundo ejercicio
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
-- RESPUESTAS --
a) Existen 2 procesos, el padre y 1 hijo creado en la linea del fork

b) El padre todo menos el if, ya que va a ejecutar la parte del else.
El hijo a partir de la linea del fork, pero ejecutará la parte del if
y saltará al print de Fin

c)  Mensaje de "Después del fork", 2 veces.
    Mensaje de "Soy el padre", 1 veces.
    Mensaje de "Soy el hijo", 1 veces.
    Mensaje de "Fin", 2 veces.
*/


void main()
{
    printf("Inicio\n");
    pid_t pid = fork();
    printf("Después del fork\n");
    if (pid == 0)
    {
        printf("Soy el hijo\n");
    }
    else
    {
        printf("Soy el padre\n");
    }
    printf("Fin\n");
}