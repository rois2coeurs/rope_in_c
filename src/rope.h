//
// Created by Valentin on 17/10/2023.
//

#ifndef ROPE_IN_C_ROPE_H
#define ROPE_IN_C_ROPE_H
#include <stdlib.h>

struct Rope {
    size_t len;
    struct Rope *left;
    struct Rope *right;
    char *str;
};

typedef struct Rope Rope;

Rope *rope_new();

void rope_insert_at(Rope *rope, char *str, size_t pos);

size_t rope_len(Rope *rope);

void rope_delete();

#endif