#include <stdio.h>

#define MAXLINE 1000

void reverse_line(char to[], char from[], int len);
int get_line(char line[], int maxline);

int main()
{

    char line[MAXLINE];
    char reverse[MAXLINE];
    int len;

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        reverse_line(reverse, line, len);
        printf("%s\n", reverse);
    }
    return 0;
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

void reverse_line(char to[], char from[], int len)
{
    for (int i = len - 1; i >= 0; --i)
    {
        to[len - i] = from[i];
    }

    to[len + 1] = '\0';
}