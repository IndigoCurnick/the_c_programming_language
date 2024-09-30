#include <stdio.h>

#define BUFSIZE 100

char buffer[BUFSIZE];
int buffer_pos = 0;

int getch(void)
{
    return (buffer_pos > 0) ? buffer[--buffer_pos] : getchar();
}

void ungetch(int c)
{
    if (buffer_pos >= BUFSIZE)
    {
        printf("ungetch: too many chars");
    }
    else
    {
        buffer[buffer_pos++] = c;
    }
}
