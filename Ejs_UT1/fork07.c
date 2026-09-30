// Séptimo ejercicio

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main()
{
 printf("CCC \n");
 if (fork()!=0)
 {
 printf("AAA \n");
 } else printf("BBB \n");
 exit(0);
}
