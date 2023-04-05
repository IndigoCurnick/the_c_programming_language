#include <stdio.h>

void alt_squeeze(char s[], char p[]);
int this_char_in_array(char p[], char s);

int main()
{

    char s[] = "hello, world";
    char p[] = "lo";

    alt_squeeze(s, p);

    printf("%s\n", s);

    return 0;
}

void alt_squeeze(char s[], char p[])
{
    int i, j; // Track s
    int k;    // track p

    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (!this_char_in_array(p, s[i]))
        {
            s[j] = s[i];
            j++;
        }
    }

    s[j] = '\0';
}

int this_char_in_array(char p[], char s)
{
    int i;

    for (i = 0; p[i] != '\0'; ++i)
    {
        if (p[i] == s)
        {
            return 1;
        }
    }

    return 0;
}