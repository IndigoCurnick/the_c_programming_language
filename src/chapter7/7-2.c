#include <stdio.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80 // Define the maximum line length

void print_char(char c);

void exercise_7_2()
{
    int c;
    int line_length = 0;

    while ((c = getchar()) != EOF)
    {
        print_char(c);
        line_length++;

        if (line_length >= MAX_LINE_LENGTH || c == '\n')
        {
            putchar('\n');
            line_length = 0;
        }
    }
}

void print_char(char c)
{
    if (isprint(c))
    {
        putchar(c);
    }
    else
    {
        printf("\\x%02X", c);
    }
}