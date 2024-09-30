#include "chapter5.h"
#include <stdio.h>
#include <ctype.h>

int getint(int *pn);

void exercise_5_1()
{
    int number = 0;

    getint(&number);

    printf("%d\n", number);
}

int getint(int *pn)
{
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

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;

    if (c != EOF)
    {
        ungetch(c);
    }

    return c;
}