#include "chapter4.h"
#include <stdio.h>

#define MAXLEN 100

void itoa2(int n, char s[]);

void exercise_4_12()
{

    char s[MAXLEN];

    int n = 144387;

    itoa2(n, s);

    printf("%s\n", s);
}

void itoa2(int n, char s[])
{

    static int i = 0;

    if (n)
    {
        if (n < 0)
        {
            s[i++] = '-';
            n *= -1;
        }

        int d = n % 10;
        n /= 10;

        itoa2(n, s);

        s[i++] = d + '0';
        s[i] = '\0';
    }
}