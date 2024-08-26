
#include "chapter4.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop_line(char s[]);

char line[MAXOP];
int line_i = 0;

void exercise_4_10()
{
    int type;
    double op2;
    char s[MAXOP];

    while (get_line(line, MAXOP) != 0)
    {
        line_i = 0;
        while ((type = getop_line(s)) != '\0')
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
}

int getop_line(char s[])
{
    int i, c;

    while ((s[0] = c = line[line_i++]) == ' ' || c == '\t')
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
        int next = line[line_i++];
        if (next == '\n' || next == ' ' || next == '\t')
        {
            --line_i;
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
        c = line[line_i++];
    }

    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = line[line_i++]))
        {
            ;
        }
    }

    if (c == '.')
    {
        while (isdigit(s[++i] = c = line[line_i++]))
        {
            ;
        }
    }

    --line_i;

    return NUMBER;
}