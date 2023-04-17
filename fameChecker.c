#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_PATH_LEN 1024



int main(int argc, char *argv[]) {

    int opt;
    char *region = NULL;
    char *especies = NULL;
    char *tipo = NULL;
    int nocontar = 0;
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
                nocontar = 1;
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
        name = argv[optind];
    }

    // Aquí puedes hacer lo que necesites con las opciones y argumentos analizados
    // Por ejemplo, imprimirlos en pantalla
    printf("region: %s", region);
    printf("species: %s", species);
    printf("type: %s", type);
    printf("nocount: %d", nocount);
    printf("list: %d", list);
    printf("size: %d", size);
    printf("name: %s", name);

    return 0;
}


    