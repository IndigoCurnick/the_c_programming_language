#include <stdio.h>

char lower(char c);

void exercise_2_10()
{
    char a = 'A';

    putchar(lower(a));
}

char lower(char c)
{
    return (c >= 'A' && c <= 'Z') ? c += 'a' - 'A' : c;
}