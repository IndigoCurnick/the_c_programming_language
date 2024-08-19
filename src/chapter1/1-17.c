#include "chapter1.h"
#include <stdio.h>

#define LIMIT 80
#define MAXLINE 100

void exercise_1_17()
{
    int len;

    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (len > LIMIT)
        {
            printf("%s", line);
        }
    }
}
