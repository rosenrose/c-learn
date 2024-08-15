#include "vector.h"

void add_vec(const int *v1, const int *v2, int *out_res)
{
    size_t i = 0;

    for (i = 0; i < VECTOR_LENGTH; i++)
    {
        *out_res = *v1 + *v2;
        out_res++;
        v1++;
        v2++;
    }
}
