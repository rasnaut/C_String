# Проект: Обработка строк на Си

## Структура проекта

```
├── main.c                        # Главная программа
├── dialog.h, dialog.c            # Модуль диалога с пользователем
├── string_processing.h/.c        # Модуль обработки строк
├── my_string.h/.c               # Пользовательский тип string
├── my_string_test_main.c        # Тесты для my_string
├── string_processing_test_main.c # Тесты для string_processing
└── Makefile                     # Файл для автоматической компиляции
```

## Компиляция

### Основная программа

```bash
gcc -c my_string.c -o my_string.o
gcc -c string_processing.c -o string_processing.o
gcc -c dialog.c -o dialog.o
gcc my_string.o string_processing.o dialog.o main.c -o main
```

Или одной командой:
```bash
gcc my_string.c string_processing.c dialog.c main.c -o main
```

### Тесты для my_string

```bash
gcc my_string.c my_string_test_main.c -o test_my_string
./test_my_string
```

### Тесты для string_processing

```bash
gcc my_string.c string_processing.c string_processing_test_main.c -o test_string_processing
./test_string_processing
```

## Использование

### Запуск основной программы

```bash
./main
```

Программа будет ждать ввода строк. Введите строки и нажмите Ctrl+D (на Linux/Mac) или Ctrl+Z + Enter (на Windows) для завершения.

### Пример использования

```
Введите строки (Ctrl+D для завершения):

   hello    world   test
Входная:  "   hello    world   test"
Выходная: "hello world test"

  foo  \t  bar  \t\t  baz  
Входная:  "  foo  	  bar  		  baz  "
Выходная: "foo bar baz"
```

## Описание функций

### my_string

- `my_string_create()` - создает пустую строку
- `my_string_from_cstr(const char *cstr)` - создает строку из С-строки
- `my_string_destroy(my_string *str)` - освобождает память
- `my_string_append_char(my_string *str, char c)` - добавляет символ
- `my_string_append_cstr(my_string *str, const char *cstr)` - добавляет С-строку
- `my_string_at(const my_string *str, size_t index)` - получает символ по индексу
- `my_string_length(const my_string *str)` - возвращает длину
- `my_string_cstr(const my_string *str)` - возвращает указатель на данные
- `my_string_clear(my_string *str)` - очищает содержимое
- `my_string_copy(const my_string *src)` - копирует строку

### string_processing

- `process_string(const my_string *input)` - основная функция обработки
- `is_delimiter(char c)` - проверяет, является ли символ разделителем
- `is_visible(char c)` - проверяет, является ли символ видимым

### dialog

- `my_readline()` - читает одну строку из stdin
- `run_dialog()` - главный цикл обработки