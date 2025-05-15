# Проект выполняют Сафин Ислам, Усманов Адель и Зыков Даниил 0907-34
## Документация по файлу filesystem.c

## Описание
Этот файл содержит реализацию базовой файловой системы в виде текстового файла с возможностью открытия, чтения и удаления "файлов", представленных в виде структурированных блоков.

## Функции

FILE* open_fs(const char* filename)`

Открывает существующий файл файловой системы или создаёт новый, если он не существует.

Параметры:
- filename (`const char*`) — имя файла файловой системы.

Возвращает:
- FILE* — дескриптор файла.

void view_file(const char* fs_filename, const char* target_filename)`

Находит и выводит содержимое одного файла из файловой системы на экран.

Возвращает:
- void — функция ничего не возвращает, только печатает содержимое.

void delete_file(const char* fs_filename, const char* target_filename)`

Удаляет файл и его содержимое из файловой системы.


void add_new_file(const char* fs_filename, const char* new_filename, const char* content_lines[], int content_count)`
Добавляет новый файл в конец файловой системы.

Параметры:
- fs_filename (`const char*`)
- new_filename (`const char*`)
- content_lines[] (`const char*[]`) — массив строк
- content_count (`int`) — количество строк

void modify_file(const char* fs_filename, const char* target_filename, const char* new_content[], int new_count)`
Заменяет содержимое файла новым.

Параметры:
- fs_filename (`const char*`)
- target_filename (`const char*`)
- new_content[] (`const char*[]`)
- new_count (`int`)


# Использование библиотеки

Мы предоставляем filesystem.c как библиотеку с заголовочным файлом filesystem.h.

Вы можете подключить её к своему проекту с помощью:

include "filesystem.h"

# Использование команд

## Создание файла и ввод содержимого

создать /test.txt
Введите содержимое (введите /end для завершения):
Привет Мир
/end

## Просмотр файла

посмотреть /test.txt
Привет Мир

## Изменение содержимого

изменить /test.txt
Новое содержимое (введите /end для завершения):
Новое содержимое файла
/end

## Удаление файла

удалить /test.txt
