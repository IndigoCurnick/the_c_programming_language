#include <stdio.h>

#define N 100
void my_strcat(char *s, char *t);

int main()
{

    char s[N] = {'H', 'E', 'L', 'L', 'O', ' ', '\0'};
    char t[N] = {'W', 'O', 'R', 'L', 'D', '\0'};

    my_strcat(s, t);

    printf("%s\n", s);

    return 0;
}

void my_strcat(char *s, char *t)
{
    char *p = s;

    while (*p != '\0')
    {
        ++p;
    }

    char *v = t;

    while (*v != '\0')
    {
        *p = *v;
        ++p;
        ++v;
    }

    *p = '\0';
}