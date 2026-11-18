#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>


volatile int segundosTranscurridos = 0;

void funcion_señal(int signum)
{
    time_t t = time(NULL);
    time(&t);
    printf("Señal de alarma recibida a las %s \n", ctime(&t));
}

int main()
{
    signal(SIGUSR1, funcion_señal);

    int num1,num2;
    printf("¿Cuántas veces sonará la alarma?: \n");
    scanf("%d", &num1);
    printf("¿Cada cuántos segundos se repetirá la alarma?: \n");
    scanf("%d", &num2);

    printf("Alarma activada \n");
    for (int i = 0; i < num1; i++)
    {
        sleep(num2);
        kill(getpid(),SIGUSR1);
    }
    printf("Alarma desactivada \n");
}