#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Erick Lazon 20111347C

//Opciones de fopen
//https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm


//Ambos procesos pueden acceder al fichero, al usar fprintf la escritura se hace con buffer
//sin embargo no podemos determinar el orden en que escribiran, esto se puede controlar añadiendo
//un wait en el else para que el padre espere que el hijo termine su ejecución. Con esto seria
//primero el hijo quien escribiria y luego el padre.


//Si ambos escriben a la vez un proceso terminaria sobrescribiendo al otro.

int main(int argc, char *argv[])
{
    FILE* file;
    //a : carga el fichero si existe, sino lo crea y apunta al ultimo caracter en el fichero.
    file= fopen("salida.txt", "a");
    //Si el fichero falla se detiene la ejecución
    if (file == NULL) {
        fprintf(stderr, "\n fallo al crear fichero");
        return 0;
    } 
    int rc = fork();

    if (rc == 0) {
        //proceso hijo
        for (int i=0; i<3; i++){
            fprintf(file, "soy el hijo iterando %d\n", i);
        }
    } else if (rc < 0) {
        //en caso de que ocurra un fallo al crear el hijo cerramos la lectura del fichero
        fprintf(stderr, "ocurrio un error\n");
        fclose(file);
        exit(1);
    }else {
        //proceso padre
        //si añadimos un wait aqui podriamos hacer que el hijo termine su escritura
        //para que luego continue el padre
        for (int i=0; i<3; i++){
            fprintf(file, "soy el padre iterando %d\n", i);
        }
    }
    fclose(file);
    
    return 0;
}