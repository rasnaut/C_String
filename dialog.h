#ifndef DIALOG_H
#define DIALOG_H

#include "my_string.h"

/**
 * Читает одну строку из стандартного входа (через scanf)
 * Использует статический буфер для чтения
 * 
 * @return Новая строка my_string с прочитанными данными
 */
my_string my_readline(void);

/**
 * Основной цикл диалога с пользователем
 * Читает строки до конца входного потока (EOF)
 * Для каждой строки выполняет обработку и вывод
 */
void run_dialog(void);

#endif // DIALOG_H