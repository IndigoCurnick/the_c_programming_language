#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)     \
    (byte & 128 ? '1' : '0'),    \
        (byte & 64 ? '1' : '0'), \
        (byte & 32 ? '1' : '0'), \
        (byte & 16 ? '1' : '0'), \
        (byte & 8 ? '1' : '0'),  \
        (byte & 4 ? '1' : '0'),  \
        (byte & 2 ? '1' : '0'),  \
        (byte & 1 ? '1' : '0')

unsigned int invert(int x, int p, int n);

void exercise_2_7()
{
    unsigned int x = 0b11111111;

    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(invert(x, 2, 4)));
}

unsigned int invert(int x, int p, int n)
{
    ++p;

    unsigned int mask1 = ~(~0 << n) << p;
    unsigned int mask2 = ~mask1 & x;

    return mask2 | ~x;
}