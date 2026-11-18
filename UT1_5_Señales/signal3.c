#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>


void funcion_señal(int signum)
{
    FILE *archivo = fopen("salidas.txt","a");

    time_t t = time(NULL);
    time(&t);

    fprintf(archivo, "Señal SIGINT recibida a las %s!\n", ctime(&t));
    fclose(archivo);
}

int main()
{
    signal(SIGINT, funcion_señal);

    while (true) {
    }
}