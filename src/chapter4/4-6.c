
#include "chapter4.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

double variables[26];
int variables_p = -1;
char var = '0';

void exercise_4_6()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop_vars(s)) != EOF)
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
        case '^':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case '~':
            push(sin(pop()));
            break;
        case '#':
            push(cos(pop()));
            break;
        case 'e':
            push(exp(pop()));
            break;
        case 'h':
            view_head();
            break;
        case 'd':
            duplicate_head();
            break;
        case 's':
            swap();
            break;
        case 'c':
            clear();
            break;
        case '=':
            store_var();
            break;
        case 'A':
            retrieve_var(var);
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

int getop_vars(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
        ;
    }

    s[1] = '\0';

    if (isupper(c))
    {
        var = c;
        return 'A';
    }

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

float peek()
{
    if (sp == 0)
    {
        printf("Error: Nothing in stack\n");
        return 0.0;
    }
    else
    {
        return stack[sp - 1];
    }
}

void store_var()
{
    if (variables_p == 25)
    {
        printf("Error: too many vars\n");
        return;
    }
    variables_p++;
    variables[variables_p] = peek();

    printf("Variable %c: %f", 'A' + variables_p, variables[variables_p]);
};

void retrieve_var(char c)
{
    int pos = c - 'A';

    if (pos > variables_p)
    {
        printf("Error: Variable not set");
        return;
    }

    push(variables[pos]);
};