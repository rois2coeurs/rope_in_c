//
// Created by Valentin on 18/10/2023.
//
#include <string.h>
#include "../src/rope.h"
#include "Unity/unity.h"

typedef struct Rope Rope;

void setUp() {}

void tearDown() {
}

void test_rope_insert_at() {
    Rope *rope = rope_new("");
    char *str = malloc(6);
    strcpy(str, "Hello");
    rope_insert_at(rope, str, 0);
    TEST_ASSERT_EQUAL(0, rope->len);
    TEST_ASSERT_EQUAL(NULL, rope->left);
    TEST_ASSERT_EQUAL(NULL, rope->right);
    TEST_ASSERT_EQUAL_STRING(str, rope->str);
    rope_delete(rope);
}

void test_rope_insert_at_2() {
    Rope *rope = rope_new("");
    char *str = malloc(16);
    strcpy(str, "HelloImValentin");
    rope_insert_at(rope, str, 0);
    TEST_ASSERT_EQUAL(7, rope->len);
    TEST_ASSERT_EQUAL(3, rope->left->len);
    TEST_ASSERT_EQUAL(4, rope->right->len);
    TEST_ASSERT_EQUAL_STRING("Hel", rope->left->left->str);
    TEST_ASSERT_EQUAL_STRING("loIm", rope->left->right->str);
    TEST_ASSERT_EQUAL_STRING("Vale", rope->right->left->str);
    TEST_ASSERT_EQUAL_STRING("ntin", rope->right->right->str);
    TEST_ASSERT_EQUAL_STRING(NULL, rope->str);
    TEST_ASSERT_EQUAL_STRING(NULL, rope->left->str);
    TEST_ASSERT_EQUAL_STRING(NULL, rope->right->str);
    rope_delete(rope);
}

void test_rope_new() {
    Rope *rope = rope_new("");
    TEST_ASSERT_EQUAL(0, rope->len);
    TEST_ASSERT_EQUAL(NULL, rope->left);
    TEST_ASSERT_EQUAL(NULL, rope->right);
    TEST_ASSERT_EQUAL(NULL, rope->str);
    rope_delete(rope);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_rope_new);
    RUN_TEST(test_rope_insert_at);
    RUN_TEST(test_rope_insert_at_2);
    return UNITY_END();
}