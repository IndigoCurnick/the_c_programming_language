#include <stdio.h>

struct Point
{
    int x;
    int y;
};

struct Rectangle
{
    struct Point p1;
    struct Point p2;
};

int area(struct Rectangle *r)
{
    int x = r->p2.x - r->p1.x;
    int y = r->p2.y - r->p1.y;

    return x * y;
}

int perimeter(struct Rectangle *r)
{
    int height = r->p2.y - r->p1.y;
    int width = r->p2.x - r->p2.x;

    return 2 * height + 2 * width;
}

struct Point makepoint(int x, int y)
{
    struct Point temp;
    temp.x = x;
    temp.y = y;

    return temp;
}

struct Rectangle makerectangle(struct Point p1, struct Point p2)
{
    struct Rectangle temp;

    temp.p1 = p1;
    temp.p2 = p2;

    return temp;
}

int main()
{
    struct Rectangle r = makerectangle(makepoint(0, 0), makepoint(10, 10));

    printf("The area of the rectangle is %d\n", area(&r));
    printf("The perimeter of this rectangle is %d\n", perimeter(&r));
    return 0;
}