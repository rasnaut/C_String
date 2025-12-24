#ifndef STRING_PROCESSING_H
#define STRING_PROCESSING_H

#include "my_string.h"

/**
 * Обрабатывает входную строку:
 * - Нормализует пробелы (разделители - пробелы и табуляции)
 * - Удаляет пробелы в начале и конце
 * - Слова разделяются одним пробелом
 * 
 * @param input Входная строка my_string
 * @return Обработанная строка my_string
 */
my_string process_string(const my_string *input);

/**
 * Проверяет, является ли символ разделителем (пробел или табуляция)
 */
int is_delimiter(char c);

/**
 * Проверяет, является ли символ видимым символом (не разделитель)
 */
int is_visible(char c);

#endif // STRING_PROCESSING_H