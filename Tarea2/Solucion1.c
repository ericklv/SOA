#define _GNU_SOURCE    //fix execvpe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// Erick Lazon 20111347C

//Basado en https://docs.python.org/2/library/os.html
//execl(path, arg0, arg1, ...)
//execle(path, arg0, arg1, ..., env)
//execlp(file, arg0, arg1, ...)
//execlpe(file, arg0, arg1, ..., env)
//execv(path, args)
//execve(path, args, env)
//execvp(file, args)
//execvpe(file, args, env)

//basicamente son el mismo proceso exec pero con distintas configuraciones
//e - Una array de punteros a variables de entorno se pasa explícitamente a la nueva imagen de proceso.
//l - Los argumentos de la línea de comandos se pasan individualmente (una lista) a la función.
//p - utiliza la variable de entorno PATH para buscar el archivo nombrado en el argumento del archivo que se ejecutará.
//v - Los argumentos de la línea de comandos se pasan a la función como un array de punteros.

int main(int argc, char const *argv[]) {
    int rc = fork();

    if (rc == 0) {
        //proceso hijo
        char * const argv[] = {"ls", "-l", "-a", NULL};
        char * const env_[] = {NULL};

        //descomentar para probar opciones
        execl("/bin/ls", argv[0], argv[1], argv[2], argv[3]);
        // execle("/bin/ls", argv[0], argv[1], argv[2], argv[3], env_);
        // execlp("ls", argv[0], argv[1], argv[2], argv[3]);

        // execv("/bin/ls", argv);
        // execvp("ls", argv);
        // execvpe("ls", argv, env_);
    }else if (rc < 0) {
        fprintf(stderr, "ocurrio un error\n");
        exit(1);
    }else{
        //proceso padre
         int wc = wait(NULL); 
         printf("termino el proceso\n");
    }
    return 0;
}