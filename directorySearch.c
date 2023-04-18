#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int count_files(char *dir_path) {
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
        } else if (S_ISDIR(st.st_mode)) {
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }
            int sub_count = count_files(path);
            if (sub_count == -1) {
                return -1;
            }
            file_count += sub_count;
        }
    }

    closedir(dir);
    return file_count;
}
