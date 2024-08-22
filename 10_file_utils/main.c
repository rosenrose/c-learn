#include <stdio.h>
#include <string.h>
#include "file_utils.h"

void print_help(void)
{
    puts("usage: a <repeat>");
    puts("usage: a <src> <dst>");
}

int main(const int argc, const char *const argv[])
{
    switch (argc)
    {
    case 2:
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            print_help();
        }
        else
        {
            print_with_repeats(argv[1]);
        }
        break;
    case 3:
        copy_file(argv[1], argv[2]);
        break;

    default:
        print_help();
        perror("Invalid arguments");
        return 1;
    }

    return 0;
}
