/* page 111 6.1 Basics of Structure */
#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

void main(void)
{
    struct point pt = {320, 200};
    printf("%d %d\n", pt.x, pt.y);

    struct rect screen;
}