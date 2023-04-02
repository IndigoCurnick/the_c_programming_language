#include <stdio.h>

int strend(char *s, char *t);

int main()
{
    char s[6] = {'H', 'E', 'L', 'L', 'O', '\0'};
    char t[3] = {'L', 'O', '\0'};

    printf("%d\n", strend(s, t));

    return 0;
}

int strend(char *s, char *t)
{
    char *v = t;

    while (*v != '\0')
    {
        ++v;
    }

    char *u = s;

    while (*u != '\0')
    {
        ++u;
    }

    while (1)
    {
        printf("u %s, v %s", *u, *v);
        if (v == 0)
        {
            return 1;
        }

        if (*v != *u)
        {
            return 0;
        }

        --u;
        --v;
    }
}