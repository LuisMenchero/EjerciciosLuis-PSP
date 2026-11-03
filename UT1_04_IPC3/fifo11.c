#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    const char *fifo1 = "FIFO1";
	int error;
	
    error=mkfifo(fifo1, 0666);

    // Abrir FIFO para escritura (bloquea hasta que el lector abra)
    int fd = open(fifo1, O_WRONLY);
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


    // Crear fifo 2
    const char *fifo2 = "FIFO2";
	int error2;
	
    error2=mkfifo(fifo2, 0666);

    int fd2 = open(fifo2, O_RDONLY);
    int resulFactorial;
    // Leer el número enviado
    if (read(fd2, &resulFactorial, sizeof(resulFactorial)) == -1) {
        printf("lector: error al leer");
        close(fd2);
        exit(EXIT_FAILURE);
    }
    printf("Factorial de %d: %d\n", numAl, resulFactorial);
    
    close(fd2);



    unlink("FIFO1");
    unlink("FIFO2");
    return 0;
    
}
