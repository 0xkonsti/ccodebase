#ifndef CORE_STRING_H_
#define CORE_STRING_H_

#include "ccodebase/core/defines.h"

typedef struct {
    char* data;
    u64 length;
} string_t;

string_t string_create(char const* data);
void string_destroy(string_t* string);

// TODO

#endif  // CORE_STRING_H_
