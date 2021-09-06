/* page 113 6.2 Structures and Functions */
#include <stdio.h>

#include "chapter06.h"

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

/* makepoint: build point by x and y */
struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

/* addpoint: add two points */
struct point addpoint(struct point pt1, struct point pt2)
{
    pt1.x += pt2.x;
    pt1.y += pt2.y;

    return pt1;
}

/* ptinrect: return 1 if p in rect 0 else */
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.y >= r.pt1.y
            && p.x < r.pt2.x && p.y < r.pt2.y;
}

/* canonrect: normalize rect */
struct rect canonrect(struct rect r)
{
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt2.y, r.pt2.y);

    return temp;
}

void test_struct_pointer()
{
    struct rect r, *rp = &r;
    r.pt1 = makepoint(3, 4);
    r.pt2 = makepoint(6, 8);

    printf("%d\n", rp->pt1.x);
    printf("%d\n", r.pt1.x);
    printf("%d\n", (rp->pt1).x);
}

struct abc {
    int len;
    char *str;
};

/* page 115 test pointer */
void test_pointer()
{
    struct abc *p;
    struct abc pp;
    pp.len = 5;
    pp.str = "AdolphLW";
    p = &pp;

    printf("%s\n", p->str);
    p->len = 6;
    (*p).str = "AdolphLWQ";
    printf("%d\n", p->len);
    printf("%s\n", p->str);
}

int main(void)
{
    // struct rect screen;
    // struct point middle;

    // screen.pt1 = makepoint(0, 0);
    // screen.pt2 = makepoint(XMAX, YMAX);

    // middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
    //                     (screen.pt1.y + screen.pt2.y)/2);
    // printf("middle point (%d, %d)\n", middle.x, middle.y);

    // struct point origin, *pp;
    // origin = makepoint(3,4);
    // pp = &origin;
    // printf("(%d, %d)\n", (*pp).x, (*pp).y);
    // printf("(%d, %d)\n", pp->x, pp->y);

    // test_struct_pointer();
    test_pointer();
    return 0;
}