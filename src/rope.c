//
// Created by Valentin on 17/10/2023.
//

#include <string.h>
#include <stdio.h>
#include "rope.h"

typedef struct Rope Rope;
const size_t MAX_ROPE_LEN = 6;

void rope_insert_at(Rope *rope, char *str, size_t pos) {
    if (rope->len == 0) {
        if (rope->str != NULL) {
            if (rope->len + strlen(str) <= MAX_ROPE_LEN) {
                str_insert_at(rope->str, str, pos);
                rope->len += strlen(str);
            } else {
                char *tmp_str = malloc(strlen(rope->str) + strlen(str) + 1);
                strcpy(tmp_str, rope->str);
                str_insert_at(tmp_str, str, pos);
                char *left = malloc(strlen(rope->str) + 1);
                char *right = malloc(strlen(rope->str) + 1);
                str_break_mid(tmp_str, left, right, strlen(tmp_str) / 2);
                rope->left = rope_new(left);
                rope->right = rope_new(right);
                rope->len += strlen(tmp_str)/2;
                free(tmp_str);
                free(left);
                free(right);
                rope->str = NULL;
            }
        } else {
            if (strlen(str) <= MAX_ROPE_LEN) {
                rope->str = malloc(strlen(str) + 1);
                strcpy(rope->str, str);
            } else {
                char *left = malloc(strlen(str) + 1);
                char *right = malloc(strlen(str) + 1);
                str_break_mid(str, left, right, strlen(str) / 2);
                rope->left = rope_new(left);
                rope->right = rope_new(right);
                rope->len += strlen(str)/2;
            }
        }
    }
    else if (rope->len > pos) {
        if (rope->left != NULL) {
            rope_insert_at(rope->left, str, pos);
        } else {
            rope->left = rope_new(str);
        }
        rope->len += strlen(str);
    }
    else if (rope->len < pos) {
        if (rope->right != NULL) {
            rope_insert_at(rope->right, str, pos - rope->len);
        } else {
            rope->right = rope_new(str);
        }
    }
}
void str_break_mid(char *str, char *left, char *right, size_t pos) {
    strncpy(left, str, pos);
    left[pos] = '\0';
    strcpy(right, str + pos);
}

void str_insert_at(char *str, char *substr, size_t pos) {
    int original_len = strlen(str);
    int substr_len = strlen(substr);
    int new_len = original_len + substr_len + 1;


    if (pos > original_len) {
        printf("Error: pos > original_len\n");
        return;
    }

    char *tmp = malloc(strlen(str) + strlen(substr) + 2);
    strncpy(tmp, str, pos);
    tmp[pos] = '\0';
    strcat(tmp, substr);
    strcat(tmp, str + pos);
    strcpy(str, tmp);
    free(tmp);
}

Rope *rope_new(char *str) {
    Rope *rope = malloc(sizeof(Rope));
    rope->len = 0;
    rope->left = NULL;
    rope->right = NULL;
    rope->str = NULL;
    rope_insert_at(rope, str, 0);
    return rope;
}

void rope_delete(Rope *rope) {
    if (rope->left != NULL) {
        rope_delete(rope->left);
    }
    if (rope->right != NULL) {
        rope_delete(rope->right);
    }
    free(rope);
}

size_t rope_len(Rope *rope) {
    if (rope->left != NULL) {
        rope_len(rope->left);
    }
    if (rope->right != NULL) {
        rope_len(rope->right);
    }
    return rope->len;
}