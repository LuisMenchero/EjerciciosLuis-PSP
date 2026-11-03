#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    const char *fifo = "PIPE02";
	int error;
	
    error=mkfifo(fifo, 0666);

    // Abrir FIFO para escritura (bloquea hasta que el lector abra)
    int fd = open(fifo, O_WRONLY);
    if (fd == -1) {
        printf("escritor: error al abrir FIFO");
        exit(EXIT_FAILURE);
    }

    // General el num aleatorio
    int numAl;
    time_t t;
    srand((unsigned)time(&t));
    // Generamos numero aleatorio entre 1 y 10
    numAl = rand() % 10;

    // Escribir el número en la FIFO
    if (write(fd, &numAl, sizeof(numAl)) == -1) {
        printf("escritor: error al escribir");
    }
    close(fd);

    // Leer resultado
    int fd2 = open(fifo, O_RDONLY);
    int resulFactorial;
    // Leer el número enviado
    if (read(fd2, &resulFactorial, sizeof(resulFactorial)) == -1) {
        printf("lector: error al leer");
        close(fd2);
        exit(EXIT_FAILURE);
    }
    printf("Factorial de %d: %d\n", numAl, resulFactorial);
    close(fd2);

    unlink("PIPE02");
    return 0;
}
