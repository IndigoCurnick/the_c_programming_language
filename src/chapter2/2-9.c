#include <stdio.h>
#include <math.h>

void printbits(unsigned int x);
int bitcount(unsigned int x);

void exercise_2_9()
{
    unsigned int x = 0b011010;

    printbits(x);
    printf("x have %d bits of 1.\n", bitcount(x));
}

void printbits(unsigned int x)
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

int bitcount(unsigned int x)
{
    int b = 0;

    while (x)
    {
        x &= (x - 1);
        ++b;
    }

    return b;
}