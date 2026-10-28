#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    int fd1[2], fd2[2];

    pipe(fd1);
    pipe(fd2);

    pid_t pid = fork();

    if (pid == 0)
    {
        close(fd1[0]);
        int numDNI;
        printf("Introduce el número de tu DNI: ");
        scanf("%d", &numDNI);
        write(fd1[1], &numDNI, sizeof(numDNI));
        close(fd1[1]);
    }
    else
    {
        wait(NULL);
        close(fd1[1]);
        int numDNI;
        read(fd1[0], &numDNI, sizeof(numDNI));
        char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
        numDNI %= 23;
        
        printf("la letra del NIF es %c \n", letra[numDNI]);

        close(fd1[0]);
    }
}
