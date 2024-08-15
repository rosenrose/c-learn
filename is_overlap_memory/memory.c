#include <stddef.h>
#include "memory.h"

int is_overlap(const int nums1[], const size_t length1, const int nums2[], const size_t length2)
{
    return (nums1 <= nums2)
               ? nums1 + length1 > nums2
               : nums2 + length2 > nums1;
}
