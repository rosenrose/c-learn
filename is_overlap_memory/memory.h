#ifndef MEMORY_H
#define MEMORY_H

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

bool is_overlap(const int nums1[], const size_t length1, const int nums2[], const size_t length2);

#endif /* MEMORY_H */
