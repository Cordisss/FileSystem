#include <stdio.h>
#include "filesystem.h"

int main() {
    const char* fs_name = "fs.txt";
    FILE* fs = open_fs(fs_name);
    if (!fs) {
        printf("Ошибка при открытии файловой системы\n");
        return 1;
    }
    fclose(fs);

    const char* content[] = {
        "Привет, мир!",
        "Это тестовый файл"
    };

    add_new_file(fs_name, "test.txt", content, 2);

    printf("\nСодержимое test.txt:\n");
    view_file(fs_name, "test.txt");

    return 0;
}
