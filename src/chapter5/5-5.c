#include "chapter5.h"
#include <stdio.h>

#define MAXLEN 100

static void my_strncpy(char *s, char *t, int n);
static void my_strncat(char *s, char *t, int n);
static int my_strncmp(char *s, char *t, int n);

void exercise_5_5()
{
    char s[MAXLEN] = "Hello this will be in the final string";
    char t[MAXLEN] = "world this will not be in the final string";

    my_strncpy(s, t, 5);

    printf("%s\n", s);

    char p[MAXLEN] = "Hello ";
    char q[MAXLEN] = "world this will not be in the final string";

    my_strncat(p, q, 5);

    printf("%s\n", p);

    char m[MAXLEN] = "Hello ";
    char n[MAXLEN] = "HellO ";

    int cmp = my_strncmp(m, n, 5);

    printf("%d\n", cmp);
}

static int my_strncmp(char *s, char *t, int n)
{
    for (int i = 0; *s != '\0' && *t != '\0' && i < n; i++)
    {
        if (*s != *t)
        {
            return *s - *t;
        }
        s++;
        t++;
    }

    return 0;
}

static void my_strncat(char *s, char *t, int n)
{

    while (*s != '\0')
    {
        s++;
    }

    int s_len = str_len(s);
    int i;

    for (i = 0; *t != '\0' && i < n; i++)
    {
        *s = *t;
        s++;
        t++;
    }

    if (i > s_len)
    {
        *s = '\0';
    }
}

static void my_strncpy(char *s, char *t, int n)
{

    int s_len = str_len(s);
    int i;

    for (i = 0; *t != '\0' && i < n; i++)
    {
        *s = *t;
        s++;
        t++;
    }

    if (i > s_len)
    {
        *s = '\0';
    }
}