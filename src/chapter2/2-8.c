#include <stdio.h>
#include <math.h>

void printbin(unsigned int x);
unsigned int rightrot(unsigned int x, unsigned int n);

void exercise_2_8()
{
    unsigned int x = 0b11110101;

    printbin(x);
    printbin(rightrot(x, 5));
}

void printbin(unsigned int x)
{
    unsigned int n = sizeof(unsigned int);

    printf("0b");

    int i;
    for (i = n * 8 - 1; i >= 0; --i)
    {
        (x & (unsigned int)pow(2, i)) ? putchar('1') : putchar('0');
    }

    putchar('\n');
}

unsigned int rightrot(unsigned int x, unsigned int n)
{
    unsigned int msb_1 = ~(~(unsigned)0 >> 1);

    int i;
    for (i = 0; i < n; ++i)
    {
        if (x & 1)
        {
            x = (x >> 1) | msb_1;
        }
        else
        {
            x = (x >> 1);
        }
    }

    return x;
}