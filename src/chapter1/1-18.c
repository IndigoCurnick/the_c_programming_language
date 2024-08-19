#include "chapter1.h"
#include <stdio.h>

#define MAXLINE 1000

void remove_trailing_blanks(char line[], int length);

void exercise_1_18()
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        remove_trailing_blanks(line, len);
        printf("%s", line);
    }
}

void remove_trailing_blanks(char line[], int length)
{
    int i;

    for (i = length - 2; line[i] == ' ' || line[i] == '\t'; --i)
        ;

    line[i + 1] = '\n';
    line[i + 2] = '\0';
}