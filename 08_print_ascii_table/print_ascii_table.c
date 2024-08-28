#include <stdio.h>
#include "print_ascii_table.h"

void print_ascii_table(void)
{
    const int MIN_ASCII = 32;
    const int MAX_ASCII = 126;
    const int CHARS_CNT = MAX_ASCII - MIN_ASCII + 1;

    const int COLS = 3;
    const int ROWS = (CHARS_CNT + (COLS - 1)) / COLS;

    int row;
    int ch;

    printf("Dec Hex  Char | Dec Hex  Char | Dec Hex  Char\n");

    for (row = 0; row < ROWS - 1; row++)
    {
        printf("%03d %#X %-4c | ", ch, ch, ch);
        ch++;

        printf("%03d %#X %-4c | ", ch, ch, ch);
        ch++;

        printf("%03d %#X %-4c\n", ch, ch, ch);
        ch++;
    }

    for (ch = MIN_ASCII; ch <= MAX_ASCII; ch++)
    {
        printf("%03d %#X %-4c | ", ch, ch, ch);
    }

    putchar('\n');
}
