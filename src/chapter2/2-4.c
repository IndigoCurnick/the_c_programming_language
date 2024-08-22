#include "chapter2.h"
#include <stdio.h>

#define MAXLINE 1000

void squeeze(char s[], char c[]);

void exercise_2_4()
{
    char s[MAXLINE]; // input
    char c[MAXLINE]; // removal chars

    get_line(s, MAXLINE);
    get_line(c, MAXLINE);

    squeeze(s, c);

    printf("%s", s);
}

void squeeze(char s[], char c[])
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; ++i)
    {
        int append = 1;

        for (int k = 0; c[k] != '\0'; ++k)
        {
            if (s[i] == c[k])
            {
                append = 0;
            }
        }

        if (append)
        {
            s[j++] = s[i];
        }
    }

    s[j] = '\0';
}