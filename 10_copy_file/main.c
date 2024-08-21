#include <stdio.h>
#include "file_utils.h"

int main(const int argc, const char *const args[])
{
    if (argc < 3)
    {
        perror("Source name and target name are required");
        return -1;
    }

    copy_file(args[1], args[2]);

    return 0;
}
