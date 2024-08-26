#include <stdio.h>

#define swap(t, x, y) \
    t tmp = x;        \
    x = y;            \
    y = tmp;

void exercise_4_14()
{
    int x = 1;
    int y = 2;
    swap(int, x, y);

    printf("x: %d\ny: %d", x, y);
}