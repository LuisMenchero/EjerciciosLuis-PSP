#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

/*
  fun_signal es la función manejadora (handler) de la señal.
   - El parámetro signum recibe el número de la señal (en este caso, SIGINT = 2).
   - Cuando el usuario pulsa Ctrl+C, en lugar de que el programa termine inmediatamente (comportamiento por defecto), se ejecuta esta función
  */

void funcion_señal(int signum)
{
    time_t t = time(NULL);
    time(&t);
    printf("Fin del proceso %d: %s \n", getpid(), ctime(&t));
}

int main()
{
    signal(SIGINT, funcion_señal); // Esta línea registra la función manejadora para la señal SIGINT. A partir de aquí, si se pulsa Ctrl+C, se ejecutará fun_signal()

    time_t t = time(NULL);
    time(&t);

    printf("Inicio del proceso %d: %s \n", getpid(), ctime(&t));
    sleep(10);
}