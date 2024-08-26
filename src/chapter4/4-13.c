#include <stdio.h>

void str_rev(char s[]);

void exercise_4_13()
{
    char s[] = "help";

    str_rev(s);

    printf("%s", s);
}

void str_rev(char s[])
{
    static int i = 0;
    static int j = 0;

    if (s[i] != '\0')
    {

        char c = s[i++];
        str_rev(s);

        s[j++] = c;
    }

    // if whole reverse process is complete, reset the static variables to make this function reusable
    if (s[j] == '\0')
    {
        i = 0;
        j = 0;
    }
}