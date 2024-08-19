#include "chapter1.h"
#include <stdio.h>

#define MAXLINE 1000

void copy(char from[], char to[]);

void exercise_1_16()
{
    int len;

    char longest[MAXLINE];
    char line[MAXLINE];

    int max = 0;

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(line, longest);
        }
    }
    if (max > 0)
    {
        printf("Longest line length: %d\n", max);
        printf("Longest line: %s", longest);
    }
}

void copy(char from[], char to[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}