//
// Created by Valentin on 18/10/2023.
//
#include <string.h>
#include "../src/rope.h"
#include "Unity/unity.h"

typedef struct Rope Rope;

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
    TEST_ASSERT_EQUAL(15, rope_len(rope));
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

void test_rope_insert_at_3() {
    Rope *rope = rope_new("");
    char *str = malloc(8);
    strcpy(str, "HelloIm");
    rope_insert_at(rope, str, 0);
    TEST_ASSERT_EQUAL(3, rope->len);
    TEST_ASSERT_EQUAL_STRING("Hel", rope->left->str);
    TEST_ASSERT_EQUAL_STRING("loIm", rope->right->str);
    TEST_ASSERT_EQUAL_STRING(NULL, rope->str);
    TEST_ASSERT_EQUAL(7, rope_len(rope));
    rope_insert_at(rope, "Middle", 4);
    TEST_ASSERT_EQUAL(13, rope_len(rope));
    TEST_ASSERT_EQUAL(3, rope->len);
    TEST_ASSERT_EQUAL(5, rope->right->len);
    rope_delete(rope);
    free(str);
}

void test_rope_new() {
    Rope *rope = rope_new("");
    TEST_ASSERT_EQUAL(0, rope->len);
    TEST_ASSERT_EQUAL(NULL, rope->left);
    TEST_ASSERT_EQUAL(NULL, rope->right);
    TEST_ASSERT_EQUAL(NULL, rope->str);
    rope_delete(rope);
}

int start_rope_tests() {
    UNITY_BEGIN();
    RUN_TEST(test_rope_new);
    RUN_TEST(test_rope_insert_at);
    RUN_TEST(test_rope_insert_at_2);
    RUN_TEST(test_rope_insert_at_3);
    return UNITY_END();
}