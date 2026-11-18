#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>


volatile int segundosTranscurridos = 0;

void funcion_señal(int signum)
{
    segundosTranscurridos += 5;
    printf("Han transcurrido %d segundos \n", segundosTranscurridos);
}

int main()
{
    signal(SIGUSR1, funcion_señal);

    while (true)
    {
        sleep(5);
        kill(getpid(),SIGUSR1);
    }
}