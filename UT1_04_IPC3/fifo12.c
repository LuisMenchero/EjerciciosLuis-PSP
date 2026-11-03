#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    // Crear fifo 1
    const char *fifo1 = "FIFO1";
	int error;
	
    error=mkfifo(fifo1, 0666);

     // Abrir FIFO para lectura (bloquea hasta que el escritor escriba)
    int fd = open(fifo1, O_RDONLY);
    if (fd == -1) {
        printf("lector: error al abrir FIFO");
        exit(EXIT_FAILURE);
    }

    int numAlLeido;
    // Leer el número enviado
    if (read(fd, &numAlLeido, sizeof(numAlLeido)) == -1) {
        printf("lector: error al leer");
        close(fd);
        exit(EXIT_FAILURE);
    }
    
    close(fd);


    // Calcular el factorial
    int resulFactorial = 1;
    for (int i = numAlLeido; i > 0; i--)
    {
        resulFactorial *= i;
    }

    // Crear fifo 2
    const char *fifo2 = "FIFO2";
	int error2;
	
    error2=mkfifo(fifo2, 0666);
	
    int fd2 = open(fifo2, O_WRONLY);
    // Escribir el número en la FIFO
    if (write(fd2, &resulFactorial, sizeof(resulFactorial)) == -1) {
        printf("escritor: error al escribir");
    }

    close(fd2);
	

    unlink("FIFO1");
    unlink("FIFO2");
    return 0;
    
}
