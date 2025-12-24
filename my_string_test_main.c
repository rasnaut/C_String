#include "my_string.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int test_count = 0;
int test_passed = 0;

void print_test(const char *test_name, int passed) {
    test_count++;
    if (passed) {
        test_passed++;
        printf("✓ PASS: %s\n", test_name);
    } else {
        printf("✗ FAIL: %s\n", test_name);
    }
}

void test_create_empty(void) {
    my_string str = my_string_create();
    print_test("create_empty", 
        my_string_length(&str) == 0 && 
        str.data != NULL);
    my_string_destroy(&str);
}

void test_append_char(void) {
    my_string str = my_string_create();
    my_string_append_char(&str, 'a');
    my_string_append_char(&str, 'b');
    int passed = (my_string_length(&str) == 2 &&
                  my_string_at(&str, 0) == 'a' &&
                  my_string_at(&str, 1) == 'b');
    print_test("append_char", passed);
    my_string_destroy(&str);
}

void test_append_cstr(void) {
    my_string str = my_string_create();
    my_string_append_cstr(&str, "hello");
    int passed = (my_string_length(&str) == 5 &&
                  strcmp(my_string_cstr(&str), "hello") == 0);
    print_test("append_cstr", passed);
    my_string_destroy(&str);
}

void test_from_cstr(void) {
    my_string str = my_string_from_cstr("world");
    int passed = (my_string_length(&str) == 5 &&
                  strcmp(my_string_cstr(&str), "world") == 0);
    print_test("from_cstr", passed);
    my_string_destroy(&str);
}

void test_clear(void) {
    my_string str = my_string_from_cstr("test");
    my_string_clear(&str);
    int passed = (my_string_length(&str) == 0 &&
                  strlen(my_string_cstr(&str)) == 0);
    print_test("clear", passed);
    my_string_destroy(&str);
}

void test_copy(void) {
    my_string str1 = my_string_from_cstr("original");
    my_string str2 = my_string_copy(&str1);
    
    int passed = (my_string_length(&str2) == my_string_length(&str1) &&
                  strcmp(my_string_cstr(&str1), my_string_cstr(&str2)) == 0);
    
    // Проверяем, что это разные объекты
    passed = passed && (str1.data != str2.data);
    
    print_test("copy", passed);
    my_string_destroy(&str1);
    my_string_destroy(&str2);
}

void test_empty_string(void) {
    my_string str = my_string_create();
    int passed = (my_string_length(&str) == 0 &&
                  strcmp(my_string_cstr(&str), "") == 0);
    print_test("empty_string", passed);
    my_string_destroy(&str);
}

void test_long_string(void) {
    my_string str = my_string_create();
    char expected[1000] = "";
    
    for (int i = 0; i < 100; i++) {
        my_string_append_cstr(&str, "abc");
        strcat(expected, "abc");
    }
    
    int passed = (my_string_length(&str) == 300 &&
                  strcmp(my_string_cstr(&str), expected) == 0);
    print_test("long_string", passed);
    my_string_destroy(&str);
}

void test_special_characters(void) {
    my_string str = my_string_create();
    my_string_append_cstr(&str, "!@#$%^&*()");
    int passed = (strcmp(my_string_cstr(&str), "!@#$%^&*()") == 0);
    print_test("special_characters", passed);
    my_string_destroy(&str);
}

void test_at_function(void) {
    my_string str = my_string_from_cstr("test");
    int passed = (my_string_at(&str, 0) == 't' &&
                  my_string_at(&str, 1) == 'e' &&
                  my_string_at(&str, 2) == 's' &&
                  my_string_at(&str, 3) == 't' &&
                  my_string_at(&str, 100) == '\0');
    print_test("at_function", passed);
    my_string_destroy(&str);
}

int main(void) {
    printf("===== MY_STRING TESTS =====\n\n");
    
    test_create_empty();
    test_append_char();
    test_append_cstr();
    test_from_cstr();
    test_clear();
    test_copy();
    test_empty_string();
    test_long_string();
    test_special_characters();
    test_at_function();
    
    printf("\n===== RESULTS =====\n");
    printf("Passed: %d/%d\n", test_passed, test_count);
    
    return (test_passed == test_count) ? 0 : 1;
}