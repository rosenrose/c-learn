#include <stdio.h>
#include "adder.h"
#include "inline_math.h"
#include "static_inline_math.h"

void run_adder(void)
{
    puts(__FILE__);
    printf("1 + 2 = %d\n", static_inline_add(1, 2));
    printf("addr of static_inline_add: %p\n", (void *)static_inline_add);

    printf("1 + 2 = %d\n", inline_add(1, 2));
    printf("addr of inline_add: %p\n", (void *)inline_add);
}
