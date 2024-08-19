#include "chapter1.h"
#include <stdio.h>

#define MAXLINE 10000

void remove_comments(char input[], char output[]);

void exercise_1_23()
{
    char line[MAXLINE];
    char no_comments[MAXLINE];

    while ((get_line(line, MAXLINE)) > 0)
    {
        remove_comments(line, no_comments);
        printf("%s", no_comments);
    }
}

void remove_comments(char input[], char output[])
{
    int slash = 0;
    int i;
    for (i = 0; input[i] != '\0'; ++i)
    {
        if (slash && input[i] == '/')
        {
            break;
        }

        if (slash)
        {
            output[i - 1] = '/';
            slash = 0;
        }

        if (input[i] == '/')
        {
            slash = 1;
            continue;
        }

        output[i] = input[i];
    }

    output[i] = '\0';
}