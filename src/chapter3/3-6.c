#include "chapter3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

// In the original, in twos compliment, the smallest negative number does not
// have a positive equivalent. Thus, `n = -n` fails.

void itoa_pad(int n, char s[], int min_width);

void exercise_3_6()
{
    char c[MAXLINE];

    itoa_pad(-111, c, 6);

    printf("%s", c);
}

void itoa_pad(int n, char s[], int min_width)
{
    int i, sign;

    sign = n;

    i = 0;
    do
    {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);

    if (i < min_width)
    {
        for (i; i < min_width; i++)
        {
            s[i] = '0';
        }
    }

    if (sign < 0)
    {
        s[i++] = '-';
    }

    s[i] = '\0';

    str_reverse(s, 0, i - 1);
}
