#include "chapter1.h"
#include <stdio.h>

#define MAXLINE 10000

#define TRUE 1
#define FALSE 0

#define BREAKING_POINT 40
#define OFFSET 5

void fold_line(char line[], char fold_str[], int n_break);

void exercise_1_22()
{
    char line[MAXLINE];
    char fold_str[MAXLINE];

    while ((get_line(line, MAXLINE)) > 0)
    {
        fold_line(line, fold_str, BREAKING_POINT);
        printf("%s", fold_str);
    }
}

void fold_line(char line[], char fold_str[], int n_break)
{
    int i, j;
    int column = 0;
    int split = FALSE;
    int last_blank = 0;

    for (i = 0, j = 0; line[i] != '\0'; ++i, ++j)
    {
        fold_str[j] = line[i];

        if (fold_str[j] == '\n')
        {
            column = 0;
        }

        column++;

        if (column == n_break - OFFSET)
        {
            split = TRUE;
        }

        if (split && (fold_str[j] == ' ' || fold_str[j] == '\t'))
        {
            last_blank = j;
        }

        if (column == n_break)
        {
            if (last_blank)
            {
                fold_str[last_blank] = '\n';
                column = j - last_blank;
                last_blank = 0;
            }
            else
            {
                fold_str[j++] = '-';
                fold_str[j] = '\n';

                column = 0;
            }

            split = FALSE;
        }
    }

    fold_str[j] = '\0';
}