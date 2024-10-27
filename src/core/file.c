#include "ccodebase/core/file.h"
#include <stdio.h>
#include <stdlib.h>
#include "ccodebase/core/defines.h"
#include "ccodebase/core/string.h"

string_t const* read_file_to_string(char const* path) {
    FILE* file = fopen(path, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file: %s | ", path);
        perror("");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    usize const file_size = ftell(file);
    rewind(file);

    char* buffer = malloc((file_size + 1) * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Failed to allocate memory for file contents\n");
        return NULL;
    }

    usize const read = fread(buffer, sizeof(char), file_size, file);
    if (read != file_size) {
        fprintf(stderr, "Could not read file: %s\n", path);
        return NULL;
    }
    buffer[file_size] = '\0';

    string_t* string = malloc(sizeof(string_t));
    if (string == NULL) {
        fprintf(stderr, "Failed to allocate memory for string\n");
        return NULL;
    }

    string->data = buffer;
    string->length = file_size;

    fclose(file);

    return string;
}
