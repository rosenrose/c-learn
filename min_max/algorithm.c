#include <assert.h>
#include <stddef.h>
#include "algorithm.h"

void get_min_max(const int nums[], const size_t length, int *const out_min, int *const out_max)
{
    size_t i;
    int min;
    int max;

    assert(length >= 1);

    min = nums[0];
    max = nums[0];

    for (i = 1; i < length; i++)
    {
        if (min > nums[i])
        {
            min = nums[i];
        }

        if (max < nums[i])
        {
            max = nums[i];
        }
    }

    *out_min = min;
    *out_max = max;
}
