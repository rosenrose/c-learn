#ifndef SHAPE_H
#define SHAPE_H

typedef struct
{
    int x;
    int y;
} point_t;

typedef struct
{
    point_t start;
    point_t end;
} line_t;

typedef struct
{
    point_t top_left;
    point_t bottom_right;
} rect_t;

rect_t build_rect(const point_t p1, const point_t p2);
int get_line_length_sq(const line_t line);
int get_rect_area(const rect_t rect);

#endif /* SHAPE_H */
