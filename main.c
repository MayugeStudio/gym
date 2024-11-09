#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#include "file_content.h"
#include "tokenizer.h"


static const char *filename = "example_1_1.rex";

int main(void)
{
    FileContent *source = read_file(filename);
    if (!source) {
        printf("Could not read file: %s\n", strerror(errno));
    }
    printf("%s\n", source->data);
    free(source);
    return 0;
}

