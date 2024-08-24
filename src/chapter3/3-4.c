#include "chapter3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

// In the original, in twos compliment, the smallest negative number does not
// have a positive equivalent. Thus, `n = -n` fails.

void itoa(int n, char s[]);

void exercise_3_4()
{
    char c[MAXLINE];

    itoa(-100, c);

    printf("%s", c);
}

void itoa(int n, char s[])
{
    int i, sign;

    sign = n;

    i = 0;
    do
    {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    s[i] = '\0';

    int s_len = strlen(s);

    str_reverse(s, 0, s_len - 1);
}
