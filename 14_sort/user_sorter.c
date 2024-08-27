#include "userdata.h"
#include "user_sorter.h"

int cmp_age_id(const void *const p1, const void *const p2)
{
    const userdata_t *const a = p1;
    const userdata_t *const b = p2;

    if (a->age == b->age)
    {
        return a->id - b->id;
    }

    return a->age - b->age;
}

int cmp_age_desc_gender(const void *const p1, const void *const p2)
{
    const userdata_t *const a = p1;
    const userdata_t *const b = p2;

    if (a->age == b->age)
    {
        return a->gender - b->gender;
    }

    return b->age - a->age;
}

int cmp_sort_key(const void *const p1, const void *const p2)
{
    const radix_userdata_t *const a = p1;
    const radix_userdata_t *const b = p2;

    return a->sort_key - b->sort_key;
}
