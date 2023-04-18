#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int directory_search(char *dir_path,int listar, int tamano, int no_contar) {
    DIR *dir;
    struct dirent *ent;
    struct stat st;
    int file_count = 0;

    dir = opendir(dir_path);
    if (dir == NULL) {
        perror("No se pudo abrir el directorio");
        return -1;
    }

    while ((ent = readdir(dir)) != NULL) {
        char path[1024];
        sprintf(path, "%s/%s", dir_path, ent->d_name);
        if (stat(path, &st) == -1) {
            perror("No se pudo obtener información del archivo");
            continue;
        }
        if (S_ISREG(st.st_mode)) {
            file_count++;
            if (listar == 1 && tamano == 0) {
               printf("Archivo: %s \n", ent->d_name); 
            } else if (listar == 0 && tamano == 1) {
                printf("Tamaño: %ld KB \n", st.st_size / 1024);
            } else if (listar == 1 && tamano == 1) {
                printf("Archivo: %s, Tamaño: %ld KB \n", ent->d_name, st.st_size / 1024);
            }
        } else if (S_ISDIR(st.st_mode)) {
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }
            int sub_count = directory_search(path,listar, tamano, no_contar);
            if (sub_count == -1) {
                return -1;
            }
            file_count += sub_count;
        }
    }

    closedir(dir);

    if (no_contar == 0){
        printf("Total de archivos: %d \n", file_count);
    }

    return file_count;
}

