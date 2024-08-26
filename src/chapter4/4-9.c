#include <stdio.h>

int getch_eof();
void ungetch_eof(int c);

void exercise_4_9()
{
    char c = getch_eof();
    printf("%c\n", c);

    ungetch_eof(EOF);
}

int eof_buf = -1;

int getch_eof()
{
    char tmp;

    if (eof_buf != -1)
    {
        tmp = eof_buf;
        eof_buf = -1;
        return tmp;
    }

    return getchar();
}

void ungetch_eof(int c)
{
    if (eof_buf != -1)
    {
        printf("Error: Buffer full");
    }
    else if (c == EOF)
    {
        printf("Error: EOF push back not possible");
    }
    else
    {
        eof_buf = c;
    }
}