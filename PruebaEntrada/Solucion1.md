# Solución 1
La jerarquía de procesos generada del siguiente código se puede ver al final, el método `fork()` presente es el encargado de generar un proceso hijo como copia del padre para cada iteración dentro del bucle generado.

``` c
#include  <sys/types.h>
#include  <sys/wait.h>
#include  <unistd.h>
#include  <stdio.h>
#include  <stdlib.h>

#define L1 2
#define L2 3

int  main (int  argc, char *argv[]) {
int cont1, cont2;
pid_t pid;
for (cont2= 0; cont2< L2; cont2++) {
for (cont1= 0; cont1< L1; cont1++) {
pid= fork();
if (pid== 0) break;
}
if (pid!= 0) break;
}
printf ("PID proceso: %d ----> PID proceso padre %d .\n",getpid(), getppid());
if (pid!= 0)

for (cont1= 0; cont1< L1; cont1++)
printf ("Fin %d.\n", wait (NULL));
return  0;
}
```

![Salida de ejecución ](https://live.staticflickr.com/65535/49979623293_fdd1d91cc5.jpg)

## Jerarquía de procesos:

* Para su correcta visualización del arbol de procesos en vscode es necesario la extensión de mermaid en vscode `ext install bierner.markdown-mermaid` 
* Una solución web 

``` mermaid
graph TD
32014 --> 32915
32915 --> 32917
32915 --> 32916
32917 --> 32919
32917 --> 32921
32921 --> 32922
32921 --> 32923
32919 --> 32927
32919 --> 32925
32916 --> 32918
32916 --> 32920
32918 --> 32926
32918 --> 32924
32920 --> 32929
32920 --> 32928
```
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE2NDk2NTI0NTQsMTY4NDk2ODQ4MCwxOT
QyNzE0NjYwXX0=
-->