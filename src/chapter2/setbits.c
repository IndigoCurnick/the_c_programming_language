#include <stdio.h>

unsigned int setbits(int x, int p, int n, int y);

int main()
{
    unsigned int x = 0b11111111;
    unsigned int y = 0b00000000;
    unsigned int z = setbits(x, 2, 4, y);
    printf("%d", z);
    return 0;
}

unsigned int setbits(int x, int p, int n, int y)
{
    ++p;

    unsigned int mask1 = (~(~(~0 << n) << p) & x);
    unsigned int mask2 = (~(~0 << n) & y) << p;

    return mask1 | mask2;
}