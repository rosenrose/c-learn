#include <stdio.h>
#include "vector.h"

int main(void)
{
    const int v1[VECTOR_LENGTH] = {1, 2, 3};
    const int v2[VECTOR_LENGTH] = {8, 4, 5};
    int res[VECTOR_LENGTH];

    add_vec(v1, v2, res);
    printf("%d %d %d\n", res[0], res[1], res[2]);

    return 0;
}
