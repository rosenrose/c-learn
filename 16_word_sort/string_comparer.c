#include <string.h>
#include "string_comparer.h"

int compare_string(const void *const p1, const void *const p2)
{
    const char **const a = (const char **)p1;
    const char **const b = (const char **)p2;

    return strcmp(*a, *b);
}

int compare_string_desc(const void *const p1, const void *const p2)
{
    const char **const a = (const char **)p1;
    const char **const b = (const char **)p2;

    return strcmp(*b, *a);
}
