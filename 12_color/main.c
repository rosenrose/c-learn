#include <stdio.h>
#include "color.h"

int main(void)
{
    color_t trans_black;
    color_t red;
    color_t yellow;

    trans_black.val = 0x0;

    red.val = 0;
    red.rgba.r = 0xff;
    red.rgba.a = 0xff;

    yellow = red;
    yellow.rgba.g = 0xff;

    printf("%llu\n", sizeof(color_t));

    printf("%6s: 0x%08x (%3d, %3d, %3d, %3d)\n",
           "black", trans_black.val,
           trans_black.rgba.r, trans_black.rgba.g, trans_black.rgba.b, trans_black.rgba.a);
    printf("%6s: 0x%08x (%3d, %3d, %3d, %3d)\n",
           "red", red.val,
           red.rgba.r, red.rgba.g, red.rgba.b, red.rgba.a);
    printf("%6s: 0x%08x (%3d, %3d, %3d, %3d)\n",
           "yellow", yellow.val,
           yellow.rgba.r, yellow.rgba.g, yellow.rgba.b, yellow.rgba.a);

    return 0;
}
