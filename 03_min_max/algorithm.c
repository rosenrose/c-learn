#include <assert.h>
#include "algorithm.h"

void get_min_max(const int nums[], const size_t length, int *const out_min, int *const out_max)
{
    size_t i;
    int min = nums[0];
    int max = nums[0];

    assert(length >= 1);

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
