//
// Created by Valentin on 23/10/2023.
//

#include <string.h>
#include <stdlib.h>
#include "../src/perso_string.h"
#include "Unity/unity.h"

typedef struct PersoString PersoString;

void test_perso_string_new() {
    char *str = malloc(6);
    strcpy(str, "Hello");
    PersoString *perso_string = perso_string_new(str);
    TEST_ASSERT_EQUAL(5, perso_string->len);
    TEST_ASSERT_EQUAL_STRING(str, perso_string->str);
    free(str);
    free(perso_string);
}

void test_perso_string_insert_at() {
    char *str = malloc(6);
    strcpy(str, "Hello");
    PersoString *perso_string = perso_string_new(str);
    perso_string_insert_at(perso_string, "World", 5);
    TEST_ASSERT_EQUAL(10, perso_string->len);
    TEST_ASSERT_EQUAL_STRING("HelloWorld", perso_string->str);
    free(str);
    free(perso_string);
}


int start_perso_string_tests() {
    UNITY_BEGIN();
    RUN_TEST(test_perso_string_new);
    RUN_TEST(test_perso_string_insert_at);
    return UNITY_END();
}