#include "chapter4.h"
#include <stdio.h>
#include <string.h>

int getstr(char line[], int limit);
void ungetstr(char line[]);

void exercise_4_7()
{
    char c[BUFSIZE];

    getstr(c, BUFSIZE);

    ungetstr(c);

    printf("%s", buffer);
}

int getstr(char line[], int limit)
{
    int i = 0, c;

    while (limit - 1 > 0 && (c = getch()) != EOF && c != '\n')
    {
        line[i++] = c;
    }

    if (c == '\n')
    {
        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}

void ungetstr(char line[])
{
    int i = strlen(line);

    while (i)
    {
        ungetch(line[--i]);
    }
}