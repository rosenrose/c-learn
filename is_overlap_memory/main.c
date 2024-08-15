#include <stdio.h>
#include "memory.h"

int main(void)
{
    int nums1[5] = {1, 2, 3, 4, 5};
    int nums2[7] = {-1, -2, 9, 6, 6, 9, 0};
    int *nums3 = nums1 + 2;
    const size_t length3 = 5u;
    int result;

    result = is_overlap(nums1, ARRAY_LENGTH(nums1), nums2, ARRAY_LENGTH(nums2));
    printf("nums1, nums2: %s\n", result ? "Yes" : "No");

    result = is_overlap(nums1, ARRAY_LENGTH(nums1), nums3, length3);
    printf("nums1, nums3: %s\n", result ? "Yes" : "No");

    return 0;
}
