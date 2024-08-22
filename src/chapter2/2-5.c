#include "chapter2.h"
#include <stdio.h>

#define MAXLINE 1000

int any(char s1[], char s2[]);

void exercise_2_5()
{
    char s[MAXLINE]; // input
    char c[MAXLINE]; // removal chars

    get_line(s, MAXLINE);
    get_line(c, MAXLINE);

    int pos = any(s, c);

    printf("%d", pos);
}

int any(char s1[], char s2[])
{

    for (int i = 0; s1[i] != '\0'; ++i)
    {
        for (int j = 0; s2[j] != '\0'; ++j)
        {
            if (s1[i] == s2[j])
            {
                return i;
            }
        }
    }

    return -1;
}