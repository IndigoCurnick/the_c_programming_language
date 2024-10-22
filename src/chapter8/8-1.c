#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 1024

int getchar(void);

void exercise_8_1()
{
    char c;

    while ((c = getchar()) != EOF)
    {
        write(1, &c, 1);
    }
}

int getchar(void)
{
    static char buf[BUFSIZE];
    static char *bufp = buf;
    static int n = 0;

    if (n == 0)
    {
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }

    return (--n >= 0) ? (unsigned char)*bufp++ : EOF;
}
