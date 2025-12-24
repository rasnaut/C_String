#include "string_processing.h"
#include <ctype.h>

int is_delimiter(char c) {
    return c == ' ' || c == '\t';
}

int is_visible(char c) {
    return !is_delimiter(c) && c != '\0';
}

my_string process_string(const my_string *input) {
    my_string output = my_string_create();
    
    if (input == NULL || input->data == NULL || input->length == 0) {
        return output;
    }
    
    int in_word = 0;
    size_t end = input->length - 1;
    while (end > 0 && is_delimiter(my_string_at(input, end))) {
        end--;
    }
    
    for (size_t i = 0; i <= end; i++) {
        char c = my_string_at(input, i);
        
        if (is_visible(c)) {
            // Добавляем символ слова
            my_string_append_char(&output, c);
            in_word = 1;
        } else {
            // Встретили разделитель
            if (in_word) {
                // Если мы были на пробеле/табуляции и начинаем новое слово
                if (my_string_length(&output) > 0) {
                    // Добавляем пробел перед новым словом (если это не первое слово)
                    my_string_append_char(&output, ' ');
                }
                in_word = 0;
            }
        }
    }
    
    return output;
}