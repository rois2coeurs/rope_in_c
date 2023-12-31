//
// Created by Valentin on 23/10/2023.
//

#ifndef ROPE_IN_C_PERSO_STRING_H
#define ROPE_IN_C_PERSO_STRING_H

#include <stddef.h>

struct PersoString {
    size_t len;
    char *str;
};

typedef struct PersoString PersoString;

void perso_string_insert_at(PersoString *perso_string, char *str, size_t pos);

PersoString *perso_string_new(char *str);

#endif //ROPE_IN_C_PERSO_STRING_H
