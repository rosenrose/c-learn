#include <stdio.h>
#include "file_utils.h"

int main(const int argc, const char *const args[])
{
    switch (argc)
    {
    case 2:
        print_with_repeats("repeat.txt");
        break;
    case 3:
        copy_file(args[1], args[2]);
        break;

    default:
        return -1;
    }

    return 0;
}
