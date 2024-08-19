#include "chapter1.h"
#include <stdio.h>

#define MAXLINE 1000
#define COLUMN_WIDTH 4

void replace_tabs(char to[], char from[], int column_width);

void exercise_1_20()
{
    int len;
    char line[MAXLINE];
    char blank_line[MAXLINE];

    while (1)
    {
        len = get_line(line, MAXLINE);
        if (len == 0)
        {
            break;
        }
        replace_tabs(blank_line, line, COLUMN_WIDTH);
        printf("%s\n", blank_line);
    }
}

void replace_tabs(char to[], char from[], int column_width)
{
    int i = 0; // Used for tracking the FROM array
    int j = 0; // Used for tracking the TO array
    int k = 0; // Used for tracking column width
    for (i = 0; from[i] != '\0'; ++i)
    {

        if (from[i] != '\t')
        {
            to[j] = from[i];
            ++j;
            ++k;

            if (k > 3)
            {
                k = 0;
            }
            continue;
        }

        while (k < 4)
        {
            to[j] = ' ';
            ++k;
            ++j;
        }
        k = 0;
    }

    to[j] = '\0';
}