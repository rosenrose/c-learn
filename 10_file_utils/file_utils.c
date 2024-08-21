#include <stdio.h>
#include "file_utils.h"

#define TRUE (1)
#define FALSE (0)

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

void print_with_repeats(const char *const filename)
{
    long repeat_pos = -1;
    int is_repeating = FALSE;
    int ch;
    FILE *file = NULL;

    fopen_s(&file, filename, "r");

    if (file == NULL)
    {
        perror("Error while opening file");
        return;
    }

    while ((ch = fgetc(file)) != EOF)
    {
        if (ch != ':')
        {
            putchar(ch);
            continue;
        }

        if (is_repeating)
        {
            /* revisited end colon */
            is_repeating = FALSE;
            repeat_pos = -1;
            continue;
        }

        if (repeat_pos < 0)
        {
            /* start colon */
            repeat_pos = ftell(file); /* 이미 :를 읽었으므로 : 바로 다음에 오는 문자를 가리킴 */

            if (repeat_pos < 0)
            {
                perror("Error while getting position");
                break;
            }
        }
        else
        {
            /* end colon */
            is_repeating = TRUE;

            if (fseek(file, repeat_pos, SEEK_SET) != 0)
            {
                perror("Eroor while fseek to position");
                break;
            }
        }
    }

    if (fclose(file) != 0)
    {
        perror("Error while closing file");
    }
}
