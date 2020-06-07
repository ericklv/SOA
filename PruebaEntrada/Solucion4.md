# Solucion 4

La razon por la que el proceso no termina es debido a que el proceso inicial accede al pipe() pero no cierra la escritura.
Esto genera un bloqueo al ejecutar wc().

La solucion seria mover el pipe() dentro del primer if, para evitar que el proceso principal pueda acceder a ella pero manteniendo el acceso para los otros 2 procesos.

```c
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]){
int tubo[2];
//se mueve el pipe dentro del primer if
if (fork()== 0){
pipe (tubo);
if (fork()== 0){
dup2 (tubo[1],STDOUT_FILENO);
close (tubo[0]);
close (tubo[1]);
execlp ("ls","ls",NULL);
}else{
dup2 (tubo[0],STDIN_FILENO);
close (tubo[0]);
close (tubo[1]);
execlp ("wc","wc","-l",NULL);
}
} else {
wait (NULL);
printf ("Fin del proceso\n");
}
return 0;
}
```
