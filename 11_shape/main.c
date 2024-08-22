#include <stdio.h>
#include "shape.h"

int main(void)
{
    point_t p1;
    point_t p2;
    line_t line1;
    line_t line2;
    rect_t rect;

    p1.x = 5;
    p1.y = 1;
    p2.x = -3;
    p2.y = 5;

    line1.start = p1;
    line1.end = p2;
    line2.start = p2;
    line2.end = p1;

    printf("line1 length_sq: %d\n", get_line_length_sq(line1));
    printf("line2 length_sq: %d\n", get_line_length_sq(line2));

    rect = build_rect(p1, p2);
    printf("rect1: (%d, %d), (%d, %d)\n",
           rect.top_left.x, rect.top_left.y,
           rect.bottom_right.x, rect.bottom_right.y);

    rect = build_rect(p2, p1);
    printf("rect2: (%d, %d), (%d, %d)\n",
           rect.top_left.x, rect.top_left.y,
           rect.bottom_right.x, rect.bottom_right.y);

    printf("rect area: %d\n", get_rect_area(rect));

    return 0;
}
