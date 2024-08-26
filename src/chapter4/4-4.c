#include "chapter4.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

void exercise_4_4()
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
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("Error: Unknown Command\n");
            break;
        }
    }
}

void view_head(void)
{
    if (sp)
    {
        printf("stack_head: %g\n", stack[sp - 1]);
    }
    else
    {
        printf("Error: stack empty.\n");
    }
}

void duplicate_head(void)
{
    double tmp = pop();
    push(tmp);
    push(tmp);
}

void swap(void)
{
    double temp1 = pop();
    double temp2 = pop();

    push(temp1);
    push(temp2);
}

void clear(void)
{
    while (sp > 0)
    {
        stack[--sp] = 0.0;
    }
}