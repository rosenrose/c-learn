#include <stdio.h>
#include "string_utils.h"

int main(void)
{
    printf("%d\n", strcmp_case_insensitive("hello", "HELL"));
    printf("%d\n", strcmp_case_insensitive("hello", "yellow"));
    printf("%d\n\n", strcmp_case_insensitive("hello", "HELLO"));

    printf("%d\n", strcmp_case_insensitive("a", "B"));
    printf("%d\n\n", strcmp_case_insensitive("A", "b"));

    printf("%d\n", strcmp_case_insensitive("AB", "ABC"));
    printf("%d\n", strcmp_case_insensitive("def", "DE"));

    return 0;
}
