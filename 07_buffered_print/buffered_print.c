#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "buffered_print.h"

#define BUFFER_LEN (32)

static size_t s_buffer_idx = 0u;
static char s_buffer[BUFFER_LEN];

void buffered_print(const char *src)
{
    size_t num_left = strlen(src);

    while (num_left > 0)
    {
        size_t copy_cnt = BUFFER_LEN - 1 - s_buffer_idx;
        const int is_buffer_empty = s_buffer_idx == 0;

        if (copy_cnt > num_left)
        {
            copy_cnt = num_left;
        }

        s_buffer_idx += copy_cnt;
        num_left -= copy_cnt;

        if (is_buffer_empty)
        {
            strncpy(s_buffer, src, copy_cnt);
            s_buffer[s_buffer_idx] = '\0';
        }
        else
        {
            strncat(s_buffer, src, copy_cnt);
        }

        src += copy_cnt;

        if (s_buffer_idx == BUFFER_LEN - 1)
        {
            printf("%s\n", s_buffer);
            s_buffer_idx = 0;
        }
    }
}
