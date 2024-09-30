#include "chapter5.h"
#include <stdio.h>
#include <ctype.h>

int getfloat(float *pn);

void exercise_5_2()
{
    float number = 0.0;

    getfloat(&number);

    printf("%f\n", number);
}

int getfloat(float *pn)
{
    double val, power;
    int c, sign;

    while (isspace(c = getch()))
    {
        ;
    }

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+')
    {
        int tmp = getch();
        if (!isdigit(tmp))
        {
            ungetch(tmp);
            return 0;
        }

        c = tmp;
    }

    for (val = 0.0; isdigit(c); c = getch())
    {
        val = 10.0 * val + (c - '0');
    }

    if (c == '.')
    {
        c = getch();
    }

    for (power = 1.0; isdigit(c); c = getch())
    {
        val = 10.0 * val + (c - '0');
        power *= 10.0;
    }

    *pn = sign * val / power;

    if (c != EOF)
    {
        ungetch(c);
    }

    return c;
}