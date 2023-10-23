//
// Created by Valentin on 23/10/2023.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "perso_string.h"

typedef struct PersoString PersoString;

PersoString *perso_string_new(char *str) {
    PersoString *perso_string = malloc(sizeof(PersoString));
    perso_string->len = strlen(str);
    perso_string->str = malloc(perso_string->len + 1);
    strcpy(perso_string->str, str);
    return perso_string;
}

void perso_string_insert_at(PersoString *perso_string, char *str, size_t pos) {
    if ((strlen(str) <= 0 || perso_string->len < pos || perso_string->str == NULL) != 0) {
        printf("Warning: perso_string_insert_at: invalid arguments\n");
        return;
    }
    char *tmp_str = malloc(perso_string->len + strlen(str) + 1);
    strcpy(tmp_str, perso_string->str);
    tmp_str[pos] = '\0';
    strcat(tmp_str, str);
    strcat(tmp_str, perso_string->str + pos);
    perso_string->len += strlen(str);
    perso_string->str = realloc(perso_string->str, strlen(tmp_str) + 1);
    assert(perso_string->str != NULL);
    strcpy(perso_string->str, tmp_str);
}