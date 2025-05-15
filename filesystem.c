#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filesystem.h"

#define MAX_FILE_SIZE 2048
#define MAX_LINES 256

// Открыть или создать файл
FILE* open_fs(const char* filename) {
    FILE* file = fopen(filename, "r+");
    if (file == NULL) {
        file = fopen(filename, "w+");
    }
    return file;
}

// Показать содержимое одного "файла"
void view_file(const char* fs_filename, const char* target_filename) {
    FILE* fs = fopen(fs_filename, "r");
    if (!fs) {
        printf("Ошибка: не удалось открыть файловую систему\n");
        return;
    }

    char buffer[MAX_FILE_SIZE] = {0};
    fread(buffer, 1, MAX_FILE_SIZE - 1, fs);
    fclose(fs);

    char* lines[MAX_LINES];
    int count = 0;

    char* token = strtok(buffer, "\n");
    while (token && count < MAX_LINES) {
        lines[count++] = token;
        token = strtok(NULL, "\n");
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(lines[i], target_filename) == 0) {
            found = 1;
            for (int j = i + 1; j < count; j++) {
                if (lines[j][0] == '/') break;
                printf("%s\n", lines[j]);
            }
            break;
        }
    }

    if (!found) {
        printf("Файл не найден\n");
    }
}

// Удалить файл
void delete_file(const char* fs_filename, const char* target_filename) {
    FILE* fs = fopen(fs_filename, "r");
    if (!fs) {
        printf("Ошибка: не удалось открыть файловую систему\n");
        return;
    }

    char buffer[MAX_FILE_SIZE] = {0};
    fread(buffer, 1, MAX_FILE_SIZE - 1, fs);
    fclose(fs);

    char* lines[MAX_LINES];
    int count = 0;

    char* token = strtok(buffer, "\n");
    while (token && count < MAX_LINES) {
        lines[count++] = token;
        token = strtok(NULL, "\n");
    }

    int start = -1, end = count;
    for (int i = 0; i < count; i++) {
        if (strcmp(lines[i], target_filename) == 0) {
            start = i;
            for (int j = i + 1; j < count; j++) {
                if (lines[j][0] == '/') {
                    end = j;
                    break;
                }
            }
            break;
        }
    }

    if (start == -1) {
        printf("Файл не найден\n");
        return;
    }

    FILE* new_fs = fopen(fs_filename, "w");
    for (int i = 0; i < count; i++) {
        if (i < start || i >= end) {
            fprintf(new_fs, "%s\n", lines[i]);
        }
    }
    fclose(new_fs);
}
