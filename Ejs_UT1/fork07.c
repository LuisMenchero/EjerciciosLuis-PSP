// Séptimo ejercicio

/*


Este código escribirá CCC y después de forma aleatoria escribirá AAA BBB o BBB AAA.


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
*/


// Código modificado para que salga CCC BBB AAA siempre
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{
 printf("CCC \n");
 if (fork()!=0)
 {
 printf("BBB \n");
 } else {
    wait(NULL);
    printf("AAA \n");
 }
 exit(0);
}
