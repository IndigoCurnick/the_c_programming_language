#include "chapter4.h"
#include <stdio.h>

#define MAXLINE 1000

int strrindex(char s[], char t[]);

void exercise_4_1()
{
    char s[MAXLINE];
    char t[MAXLINE];

    get_line(s, MAXLINE);
    get_line(t, MAXLINE);

    int index = strrindex(s, t);

    printf("Index: %d", index);
}

int strrindex(char s[], char t[])
{

    int i, j, k;
    int first_match = -1;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
        {
            ;
        }
        if (k > 0 && t[k] == '\0')
        {
            first_match = i;
        }
    }

    return first_match;
}