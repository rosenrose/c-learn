#ifndef HASH_FUNCTION_H
#define HASH_FUNCTION_H

size_t hash_int(const int val);
size_t hash_float(const float val);
size_t hash_data(const void *const data, const size_t length);

#endif /* HASH_FUNCTION_H */
