#include "chapter4.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFFSIZE 100
#define NUMBER '0'

int getop_static(char[]);

void exercise_4_11()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop_static(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;

        case '+':
            push(pop() + pop());
            break;

        case '-':
            op2 = pop();
            push(pop() - op2);
            break;

        case '*':
            push(pop() * pop());
            break;

        case '/':
            op2 = pop();

            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("Error: zero divisor.\n");
            }

            break;

        case '%':
            op2 = pop();

            if (op2 != 0.0)
            {
                push((int)pop() % (int)op2);
            }
            else
            {
                printf("Error: zero divisor.\n");
            }
            break;

        case '\n':
            printf("\t%.8g\n", pop());
            break;

        default:
            printf("Error: unknown command %s.\n", s);
            break;
        }
    }
}

int getop_static(char s[])
{
    int i = 0, c;
    static int buf = EOF;

    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }

    if (c == '-')
    {
        int next = getchar();
        if (!isdigit(next) && next != '.')
        {
            return next;
        }

        s[i] = c;
        c = next = buf;
    }
    else
    {
        c = getchar();
    }

    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getchar()))
            ;
    }

    if (c == '.')
    {
        while (isdigit(s[++i] = c = getchar()))
            ;
    }

    if (c != EOF)
    {
        buf = c;
    }

    return NUMBER;
}