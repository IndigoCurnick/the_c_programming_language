
#include "chapter4.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

void exercise_4_5()
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
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("Error: Unknown Command\n");
            break;
        }
    }
}