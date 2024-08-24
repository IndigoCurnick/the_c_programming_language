#include "chapter3.h"
#include <stdio.h>

#define MAXLINE 1000

void escape(char s[], char t[]);
void reverse_escape(char s[], char t[]);

void exercise_3_2()
{

    printf("Convert special chars to escapes\n");

    char s[MAXLINE];
    char t[MAXLINE];

    get_line(s, MAXLINE);
    escape(s, t);
    printf("%s\n", t);

    printf("Convert escapes into special chars\n");

    char m[MAXLINE];
    char n[MAXLINE];

    get_line(m, MAXLINE);
    reverse_escape(m, n);
    printf("%s\n", n);
}

void escape(char s[], char t[])
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

void reverse_escape(char s[], char t[])
{
    int i = 0;
    int j = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '\\' && s[i + 1] == '\\')
        {
            switch (s[i + 2])
            {
            case 'n':
                t[j] = '\n';
                ++j;
                i += 3;
                break;
            case 't':
                t[j] = '\t';
                ++j;
                i += 3;
                break;
            default:
                ++i;
            }
        }
        else
        {
            t[j] = s[i];
            ++i;
            ++j;
        }
    }
}