#include <stdio.h>

int alt_strpbrk(char s[], char p[]);
int this_char_in_array(char p[], char s);

int main()
{

    char s[] = "hello, world";
    char p[] = "lo";

    int index = alt_strpbrk(s, p);

    printf("Frist appearance of char in p is index %d\n", index);

    return 0;
}

int alt_strpbrk(char s[], char p[])
{
    int i; // Track s

    for (i = 0; s[i] != '\0'; i++)
    {
        if (this_char_in_array(p, s[i]))
        {
            return i;
        }
    }

    return -1;
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