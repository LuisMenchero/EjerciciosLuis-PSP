// Tercer ejercicio
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

c)  Mensaje de "Inicio", 1 vez por el padre.
    Mensaje de "Después del fork", 2 veces una por el padre y una por el hijo.
    Mensaje de "Soy el padre", 1 vez por el padre.
    Mensaje de "Soy el hijo", 1 vez por el hijo.
    Mensaje de "Fin", 2 veces una por el padre y una por el hijo.
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