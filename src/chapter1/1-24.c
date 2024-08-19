#include "chapter1.h"
#include <stdio.h>

#define MAXLINE 10000

int check_brackets(char input[]);

void exercise_1_24()
{
    char line[MAXLINE];

    while ((get_line(line, MAXLINE)) > 0)
    {
        int balanced = check_brackets(line);
        if (balanced)
        {
            printf("No errors detected\n");
        }
        else
        {
            printf("Unbalanced opening and closing brackets\n");
        }
    }
}

int check_brackets(char input[])
{
    int opening = 0;
    int closing = 0;

    for (int i = 0; input[i] != '\0'; ++i)
    {
        if (input[i] == '(')
        {
            ++opening;
        }
        else if (input[i] == ')')
        {
            ++closing;
        }
    }

    return opening == closing;
}