#include "chapter3.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int char_in_range(char c);

// Try input like
// a-z
// A-Z
// 0-9
// -a-z-
// -a-zA-Z0-9-

void exercise_3_3()
{
    char c[MAXLINE];

    int len = get_line(c, MAXLINE);
    len = len - 1; // Remember, there is a newline at the end

    int in_sequence = 0;
    int lower = -1;

    for (int i = 0; i <= len; ++i)
    {

        if (c[i] == '-' && !in_sequence)
        {
            printf("-");
            continue;
        }

        if (in_sequence && char_in_range(c[i]))
        {

            for (int j = lower; j <= c[i]; ++j)
            {
                printf("%c", j);
            }

            if (c[i + 1] != '-')
            {
                in_sequence = 0;
            }

            continue;
        }

        if (char_in_range(c[i]) && !in_sequence)
        {
            in_sequence = 1;
            lower = c[i];
            continue;
        }
    }
}

int char_in_range(char c)
{

    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}