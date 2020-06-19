#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

//Erick Lazon 20111347C

//STDOUT_FILENO es un descriptor de archivo numérico, cuando se usa en close se cierra y ya no se permite
//la salida mediante prinf, sin embargo debemos notar que al usarse dentro del proceso hijo solo se cierra
//para este proceso. 
//Podemos notar que aun si usamos printf sin salto de linea antes del close este se queda en el buffer 
//y por tanto no se muestra. Pero si añadimos el salto de linea se muestra correctamente antes del cierre.

int main()
{
    pid_t rc = fork();

    if (rc == 0){
        //proceso hijo
        // write(1, "salida antes de cerrar stdout\n", strlen("salida antes de cerrar stdout\n"));
        printf("salida antes de cerrar stdout");
        // printf("salida antes de cerrar stdout\n");
        close(STDOUT_FILENO);
        // write(1, "salida despues de cerrar stdout\n", strlen("salida despues de cerrar stdout\n"));
        printf("salida despues de cerrar stdout\n");
    }
    else if (rc < 0){
        //fallo al crear el proceso hijo
        printf("ocurrio un error\n");
        
    }else {
        //proceso padre
        wait(NULL);
        printf("salida del padre\n");
    }
}