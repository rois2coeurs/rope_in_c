//
// Created by Valentin on 17/10/2023.
//

#include <string.h>
#include "rope.h"

typedef struct Rope Rope;
const size_t MAX_ROPE_LEN = 6;

void rope_insert_at(Rope *rope, char *str, size_t pos) {
    if (!rope->len || rope->len == 0) {
        rope->str = str;
        rope->len = strlen(str);
        return;
    }
    if (rope->len < pos) {
        if (!rope->right) { rope->right = rope_new(); }
        rope_insert_at(rope->right, str, pos - rope->len);
        return;
    }
    if (rope->len > pos) {
        if (!rope->left) { rope->left = rope_new(); }
        rope_insert_at(rope->left, str, pos);
        return;
    }
}

Rope *rope_new() {
    Rope *rope = malloc(sizeof(Rope));
    rope->len = 0;
    rope->left = NULL;
    rope->right = NULL;
    rope->str = NULL;
    return rope;
}