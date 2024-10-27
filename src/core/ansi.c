#define _CRT_SECURE_NO_WARNINGS

#include "ccodebase/core/ansi.h"
#include <stdlib.h>
#include <string.h>

char* ansi_formated(char const* str, ansi_t fmt) {
    char* result = (char*)malloc(strlen(fmt) + strlen(str) + strlen(ANSI_RESET) + 1);
    strcpy(result, fmt);
    strcat(result, str);
    strcat(result, ANSI_RESET);
    return result;
}
