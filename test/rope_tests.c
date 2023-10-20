//
// Created by Valentin on 18/10/2023.
//
#include <string.h>
#include "../src/rope.h"
#include "Unity/unity.h"

typedef struct Rope Rope;

void setUp() {}

void tearDown() {}

void test_rope_new() {
    Rope *rope = rope_new();
    TEST_ASSERT_EQUAL(0, rope->len);
    TEST_ASSERT_EQUAL(NULL, rope->left);
    TEST_ASSERT_EQUAL(NULL, rope->right);
    TEST_ASSERT_EQUAL(NULL, rope->str);
    free(rope);
}

void test_rope_insert_at() {
    Rope *rope = rope_new();
    char *str = "Hello";
    rope_insert_at(rope, str, 0);
    TEST_ASSERT_EQUAL(5, rope->len);
    TEST_ASSERT_EQUAL(NULL, rope->left);
    TEST_ASSERT_EQUAL(NULL, rope->right);
    TEST_ASSERT_EQUAL_STRING(str, rope->str);
    free(rope);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_rope_new);
    RUN_TEST(test_rope_insert_at);
    return UNITY_END();
}