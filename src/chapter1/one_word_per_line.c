#include <stdio.h>

#define IN 1  // Inside word
#define OUT 0 // Outside word

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            putchar('\n');
        }
        else
        {
            putchar(c);
        }
    }

    return 0;
}