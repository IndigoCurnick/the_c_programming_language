#include <stdio.h>

void exercise_1_10()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else
        {
            putchar(c);
        }
    }
}