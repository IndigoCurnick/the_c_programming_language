#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
int escape(char s[], char t[]);

int main()
{
    int len;
    char s[MAXLINE];
    char t[MAXLINE];

    while ((len = get_line(s, MAXLINE)) > 0)
    {
        printf("%s\n", s);
        escape(s, t);
        printf("%s\n", t);
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

int escape(char s[], char t[])
{
    int j = 0;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        switch (s[i])
        {
        case '\n':
            t[j] = '\\';
            ++j;
            t[j] = 'n';
            ++j;
            break;
        case '\t':
            t[j] = '\\';
            ++j;
            t[j] = 't';
            ++j;
            break;
        default:
            t[j] = s[i];
            ++j;
            break;
        }
    }
    t[j] = '\0';
}