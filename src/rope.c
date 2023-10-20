//
// Created by Valentin on 17/10/2023.
//

#include <string.h>
#include "rope.h"

typedef struct Rope Rope;
const size_t MAX_ROPE_LEN = 6;

void rope_insert_at(Rope *rope, char *str, size_t pos) {
    // TODO: implement
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