#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "directorySearch.h"
#define MAX_PATH_LEN 1024



int main(int argc, char *argv[]) {

    int opt;
    char *region = NULL;
    char *especies = NULL;
    char *tipo = NULL;
    int no_contar = 0;
    int listar = 0;
    int tamano = 0;
    char *nombre = NULL;

    while ((opt = getopt(argc, argv, "r:s:t:clz")) != -1) {
        switch (opt) {
            case 'r':
                region = optarg;
                break;
            case 's':
                especies = optarg;
                break;
            case 't':
                tipo = optarg;
                break;
            case 'c':
                no_contar = 1;
                break;
            case 'l':
                listar = 1;
                break;
            case 'z':
                tamano = 1;
                break;
            default:
                break;
        }
    }

    if (optind < argc) {
        nombre = argv[optind];
    }

    // Aquí puedes hacer lo que necesites con las opciones y argumentos analizados
    // Por ejemplo, imprimirlos en pantalla
    printf("region: %s   ", region);
    printf("especies: %s   ", especies);
    printf("tipo: %s    ", tipo);
    printf("no_contar: %d   ", no_contar);
    printf("listar: %d   ", listar);
    printf("tamano: %d   ", tamano);
    printf("nombre: %s   ", nombre);

   
    printf("Cantidad de items %d \n",count_files(region));

    return 0;
}