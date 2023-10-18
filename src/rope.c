//
// Created by Valentin on 17/10/2023.
//

#include <string.h>
#include "rope.h"

typedef struct Rope Rope;

void rope_insert_at(Rope *rope, char *str, size_t pos) {
    if (rope->len == 0) {
        rope->str = str;
        rope->len = strlen(str);
    }
    if (rope->len < pos) {
        rope_insert_at(rope->right, str, pos - rope->len);
    }
    if (rope->len > pos) {
        rope_insert_at(rope->left, str, pos);
    }
}

size_t rope_len(Rope *rope) {
    return 1;
}

Rope *rope_new() {
    Rope *rope = malloc(sizeof(Rope));
    rope->len = 0;
    rope->left = NULL;
    rope->right = NULL;
    rope->str = NULL;
    return rope;
}

void rope_delete() {

}