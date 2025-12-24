#include "string_processing.h"
#include "my_string.h"
#include <stdio.h>
#include <string.h>

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

void test_single_word(void) {
    my_string input = my_string_from_cstr("hello");
    my_string output = process_string(&input);
    
   
    int passed = strcmp(my_string_cstr(&output), "hello") == 0;
    print_test("single_word", passed);
    if(!passed) {
        printf("Input: ");  my_string_print(&input);
        printf("Output: "); my_string_print(&output);
    }
    
    my_string_destroy(&input);
    my_string_destroy(&output);
}

void test_multiple_words(void) {
    my_string input = my_string_from_cstr("hello world test");
    my_string output = process_string(&input);
    
    int passed = strcmp(my_string_cstr(&output), "hello world test") == 0;
    print_test("multiple_words", passed);
    
    my_string_destroy(&input);
    my_string_destroy(&output);
}

void test_extra_spaces(void) {
    my_string input = my_string_from_cstr("hello   world");
    my_string output = process_string(&input);
    
    int passed = strcmp(my_string_cstr(&output), "hello world") == 0;
    print_test("extra_spaces", passed);
    
    my_string_destroy(&input);
    my_string_destroy(&output);
}

void test_leading_spaces(void) {
    my_string input = my_string_from_cstr("   hello world");
    my_string output = process_string(&input);
    
    int passed = strcmp(my_string_cstr(&output), "hello world") == 0;
    print_test("leading_spaces", passed);
    
    my_string_destroy(&input);
    my_string_destroy(&output);
}

void test_trailing_spaces(void) {
    my_string input = my_string_from_cstr("hello world   ");
    my_string output = process_string(&input);
    
    int passed = strcmp(my_string_cstr(&output), "hello world") == 0;
    print_test("trailing_spaces", passed);
    if(!passed) {
        printf("Input: <hello world>\n");
        printf("Output: <%s>\n", output.data); 
    }
    
    my_string_destroy(&input);
    my_string_destroy(&output);
}

void test_tabs(void) {
    my_string input = my_string_from_cstr("hello\tworld\ttest");
    my_string output = process_string(&input);
    
    int passed = strcmp(my_string_cstr(&output), "hello world test") == 0;
    print_test("tabs", passed);
    
    my_string_destroy(&input);
    my_string_destroy(&output);
}

void test_mixed_whitespace(void) {
    my_string input = my_string_from_cstr("  hello  \t  world\t\t test  ");
    my_string output = process_string(&input);
    
    int passed = strcmp(my_string_cstr(&output), "hello world test") == 0;
    print_test("mixed_whitespace", passed);
    if(!passed) {
        printf("Input: <hello world test>\n");
        printf("Output: <%s>\n", output.data); 
    }
    
    my_string_destroy(&input);
    my_string_destroy(&output);
}

void test_empty_string(void) {
    my_string input = my_string_from_cstr("");
    my_string output = process_string(&input);
    
    int passed = strcmp(my_string_cstr(&output), "") == 0;
    print_test("empty_string", passed);
    
    my_string_destroy(&input);
    my_string_destroy(&output);
}

void test_only_spaces(void) {
    my_string input = my_string_from_cstr("     ");
    my_string output = process_string(&input);
    
    int passed = strcmp(my_string_cstr(&output), "") == 0;
    print_test("only_spaces", passed);
    
    my_string_destroy(&input);
    my_string_destroy(&output);
}

void test_single_space(void) {
    my_string input = my_string_from_cstr(" ");
    my_string output = process_string(&input);
    
    int passed = strcmp(my_string_cstr(&output), "") == 0;
    print_test("single_space", passed);
    
    my_string_destroy(&input);
    my_string_destroy(&output);
}

void test_is_delimiter(void) {
    int passed = (is_delimiter(' ') && 
                  is_delimiter('\t') && 
                  !is_delimiter('a') &&
                  !is_delimiter('0'));
    print_test("is_delimiter", passed);
}

void test_is_visible(void) {
    int passed = (is_visible('a') && 
                  is_visible('0') &&
                  !is_visible(' ') &&
                  !is_visible('\t') &&
                  !is_visible('\0'));
    print_test("is_visible", passed);
}

int main(void) {
    printf("===== STRING_PROCESSING TESTS =====\n\n");
    
    test_single_word();
    test_multiple_words();
    test_extra_spaces();
    test_leading_spaces();
    test_trailing_spaces();
    test_tabs();
    test_mixed_whitespace();
    test_empty_string();
    test_only_spaces();
    test_single_space();
    test_is_delimiter();
    test_is_visible();
    
    printf("\n===== RESULTS =====\n");
    printf("Passed: %d/%d\n", test_passed, test_count);
    
    return (test_passed == test_count) ? 0 : 1;
}