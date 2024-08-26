#include "chapter4.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 100

double atof(char s[]);

void exercise_4_2()
{
    char c[MAXLINE];

    get_line(c, MAXLINE);

    double res = atof(c);

    printf("%f", res);
}

double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
    {
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.')
    {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    double so_far = sign * val / power;

    printf("%c\n", s[i]);

    if (s[i] != 'e' && s[i] != 'E')
    {
        return so_far;
    }

    i++;
    int new_sign = (s[i] == '-') ? -1 : 1;
    i++;
    int res = 0;

    for (i; isdigit(s[i]); i++)
    {
        res = res * 10 + s[i] - '0';
    }

    if (new_sign == 1)
    {
        double p = pow(10.0, res);
        so_far *= p;
    }
    else
    {
        double p = pow(10.0, res);
        so_far /= p;
    }

    return so_far;
}