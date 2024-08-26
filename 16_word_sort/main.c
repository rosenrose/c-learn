#include <stdio.h>
#include <stdlib.h>
#include "string_comparer.h"

enum
{
    WORDS_CNT = 6
};

int main(void)
{
    size_t i;
    const char *words[WORDS_CNT] = {"preminum", "level", "cultured", "moaning", "skinny", "curve"};

    puts("Sort ascending");
    qsort(words, WORDS_CNT, sizeof(char *), compare_string);

    for (i = 0; i < WORDS_CNT; i++)
    {
        puts(words[i]);
    }

    puts("\nSort descending");
    qsort(words, WORDS_CNT, sizeof(char *), compare_string_desc);

    for (i = 0; i < WORDS_CNT; i++)
    {
        puts(words[i]);
    }

    return 0;
}
