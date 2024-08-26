#include <stdio.h>

int getch_short();
void ungetch_short(int c);

void exercise_4_8()
{
    char c = getch_short();
    printf("%c\n", c);

    ungetch_short(c);

    printf("%c\n", c = getch_short());
}

int buf = -1;

int getch_short()
{
    char tmp;

    if (buf != -1)
    {
        tmp = buf;
        buf = -1;
        return tmp;
    }

    return getchar();
}

void ungetch_short(int c)
{
    if (buf != -1)
    {
        printf("Error: Buffer full");
    }
    else
    {
        buf = c;
    }
}