#include <stdio.h>
#include "file_utils.h"

void close_file(FILE *const file)
{
    if (fclose(file) != 0)
    {
        perror("Error while closing file");
    }
}

void copy_file(const char *const src, const char *const dst)
{
    FILE *src_file = NULL;
    FILE *dst_file = NULL;
    int ch;

    fopen_s(&src_file, src, "rb");

    if (src_file == NULL)
    {
        perror("Error while opening source file");
        return;
    }

    fopen_s(&dst_file, dst, "wb");

    if (dst_file == NULL)
    {
        perror("Error while creating target file");
        close_file(src_file);
        return;
    }

    while ((ch = fgetc(src_file)) != EOF)
    {
        fputc(ch, dst_file);
    }

    close_file(dst_file);
    close_file(src_file);
}
