#include "file_content.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FileContent *read_file(const char *filename)
{
    FileContent *result = malloc(sizeof(FileContent));
    FILE *f = fopen(filename, "r");
    if (!f) {
        result = NULL;
        goto defer;
    }
    if (fseek(f, 0, SEEK_END) < 0) {
        result = NULL; 
        goto defer;
    }
    long m = ftell(f);
    if (m < 0) {
        result = NULL;
        goto defer;
    }
    if (fseek(f, 0, SEEK_SET) < 0) {
        result = NULL;
        goto defer;
    }

    result->data = (char*)malloc(m*sizeof(char));
    result->size = m;
    if (fread(result->data, sizeof(char), m, f) == 0) {
        result = NULL;
        goto defer;
    }

defer:
    if (f) fclose(f);
    if (!result) free(result);
    return result;
}
