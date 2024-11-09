#define NOB_IMPLEMENTATION
#include "nob.h"

#define CC     "cc"
#define CFLAGS "-Wall", "-Wextra"

bool build_all()
{
    Nob_Cmd cmd = {0};
    // tokenizer.c
    {
        nob_cmd_append(&cmd, CC, CFLAGS, "-c", "tokenizer.c");
        if (!nob_cmd_run_sync_and_reset(&cmd)) return false;
    }
    // file_content.c
    {
        nob_cmd_append(&cmd, CC, CFLAGS, "-c", "file_content.c");
        if (!nob_cmd_run_sync_and_reset(&cmd)) return false;
    }
    // main.c
    {
        nob_cmd_append(&cmd, CC, CFLAGS);
        nob_cmd_append(&cmd, "-o", "main", "main.c", "file_content.o");
        if (!nob_cmd_run_sync_and_reset(&cmd)) return false;
    }

    return true;
}

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);
    if (!build_all()) {
        return 1;
    }
    return 0;
}
