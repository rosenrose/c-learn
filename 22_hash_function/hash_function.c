#include <stddef.h>
#include "hash_function.h"

size_t hash_int(const int val)
{
    return val;
}

size_t hash_float(const float val)
{
    return *((size_t *)&val);
}

size_t hash_data(const void *const data, const size_t length)
{
    const char *ptr = data;
    size_t hash = 0;
    size_t i;

    for (i = 0; i < length; i++)
    {
        hash = (65599 * hash) + *ptr;
        ptr++;
    }

    return hash ^ (hash >> 16);
}
