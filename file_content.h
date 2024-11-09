#ifndef FILE_CONTENT_H_
#define FILE_CONTENT_H_

#include <stddef.h>

typedef struct {
    char *data;
    size_t size;
} FileContent;

FileContent *read_file(const char *filename);

#endif // FILE_CONTENT_H_
