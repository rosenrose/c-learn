#include <ctype.h>
#include "string_utils.h"

int strcmp_case_insensitive(const char *a, const char *b)
{
    while (*a != '\0' && tolower(*a) == tolower(*b))
    {
        a++;
        b++;
    }

    if (*a == *b)
    {
        return 0;
    }

    return (*a < *b) ? -1 : 1;
}
