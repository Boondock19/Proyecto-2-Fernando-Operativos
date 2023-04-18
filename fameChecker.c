#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "directorySearch.h"
#define MAX_PATH_LEN 1024



int main(int argc, char *argv[]) {

    int opt;
    char *region = NULL;
    char *especie = NULL;
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
                especie = optarg;
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

   
    directory_search(region,listar,tamano,no_contar);

    return 0;
}