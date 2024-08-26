#include "chapter4.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

char buffer[BUFSIZE];
int buffer_pos = 0;
int sp = 0;
double stack[MAXVAL];

void exercise_4_3()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("Divide by 0 error\n");
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
                printf("Divide by 0 error\n");
            }
            break;

        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("Error: Unknown Command\n");
            break;
        }
    }
}

void push(double f)
{
    if (sp < MAXVAL)
    {
        stack[sp++] = f;
    }
    else
    {
        printf("Full stack error\n");
    }
}

double pop(void)
{
    if (sp > 0)
    {
        return stack[--sp];
    }
    else
    {
        printf("Stack empty error\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
        ;
    }

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c; // Not a number
    }

    i = 0;

    if (c == '-')
    {
        int next = getch();
        if (next == '\n' || next == ' ' || next == '\t')
        {
            ungetch(next);
            return c; // return '-' as operator
        }
        else if (!isdigit(next) && next != '.')
        {
            return next; // not a number
        }
        else // number like "-5", "-.6" etc, next is digit or '.'
        {
            s[++i] = c = next;
        }
    }
    else
    {
        c = getch();
    }

    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }

    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }

    if (c != EOF)
    {
        ungetch(c);
    }

    return NUMBER;
}

int getch(void)
{
    return (buffer_pos > 0) ? buffer[--buffer_pos] : getchar();
}

void ungetch(int c)
{
    if (buffer_pos >= BUFSIZE)
    {
        printf("ungetch: too many chars");
    }
    else
    {
        buffer[buffer_pos++] = c;
    }
}
