#include <stdlib.h>
#include "shape.h"

rect_t build_rect(const point_t p1, const point_t p2)
{
    rect_t rect;

    if (p1.x < p2.x)
    {
        rect.top_left.x = p1.x;
        rect.bottom_right.x = p2.x;
    }
    else
    {
        rect.top_left.x = p2.x;
        rect.bottom_right.x = p1.x;
    }

    if (p1.y < p2.y)
    {
        rect.top_left.y = p1.y;
        rect.bottom_right.y = p2.y;
    }
    else
    {
        rect.top_left.y = p2.y;
        rect.bottom_right.y = p1.y;
    }

    return rect;
}

int get_line_length_sq(const line_t line)
{
    const int x_diff = line.start.x - line.end.x;
    const int y_diff = line.start.y - line.end.y;

    return x_diff * x_diff + y_diff * y_diff;
}

int get_rect_area(const rect_t rect)
{
    const int width = abs(rect.bottom_right.x - rect.top_left.x);
    const int height = abs(rect.bottom_right.y - rect.top_left.y);

    return width * height;
}
