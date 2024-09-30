#include "chapter5.h"
#include <stdio.h>

#define MAXLEN 1000

void strcat(char *s, char *t);

void exercise_5_3()
{
    char s[MAXLEN], t[MAXLEN];

    get_line(s, MAXLEN);
    get_line(t, MAXLEN);

    strcat(s, t);

    printf("%s\n", s);
}

void strcat(char *s, char *t)
{

    while (*s != '\0')
    {
        s++;
    }

    while (*s++ = *t++)
    {
        ;
    }
}