//
// Created by Valentin on 18/10/2023.
//
#include <assert.h>
#include <string.h>
#include "../src/rope.h"

typedef struct Rope Rope;

int main() {
    Rope *rope = rope_new();
    rope_insert_at(rope, "Hello", 0);
    rope_insert_at(rope, "World", 5);
    rope_insert_at(rope, "!", 1);
    assert(strcmp(rope->str, "H!elloWorld") == 0);
    free(rope);
}