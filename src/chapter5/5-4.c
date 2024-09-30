#include "chapter5.h"
#include <stdio.h>

#define MAXLEN 1000

int strend(char *s, char *t);

void exercise_5_4()
{
    char s[MAXLEN], t[MAXLEN];

    get_line(s, MAXLEN);
    get_line(t, MAXLEN);

    int end = strend(s, t);
    printf("1 Indicates that string 2 is at the end of string 1, 0 indicates not\n");
    printf("%d\n", end);
}

int str_len(char *s)
{
    char *p = s;

    while (*p != '\0')
    {
        p++;
    }

    return p - s;
}

int strend(char *s, char *t)
{

    int s_len = str_len(s);
    int t_len = str_len(t);

    printf("s_len %d, t_len %d\n", s_len, t_len);
    int diff = s_len - t_len;

    if (diff <= 0)
    {
        return 0; // t can not be at the end of s if t is bigger than s
    }

    s += s_len - t_len;

    for (; *s != '\0'; s++, t++)
    {
        if (*s != *t)
        {
            return 0;
        }
    }

    return 1;
}