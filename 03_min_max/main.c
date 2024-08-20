#include <stdio.h>
#include "algorithm.h"

#define LENGTH (5)

int main(void)
{
    const int nums[LENGTH] = {4, 10, 9, -1, 7};
    int min;
    int max;

    get_min_max(nums, LENGTH, &min, &max);

    printf("min: %d\n", min);
    printf("max: %d\n", max);

    return 0;
}
