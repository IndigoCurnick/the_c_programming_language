#include <stdio.h>

#define MAXLINE 1000
#define PRINT_LENGTH 10

int get_line(char line[], int maxlength);

void exercise_1_16()
{

    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (len > PRINT_LENGTH)
        {
            printf("%s", line);
        }
    }
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}