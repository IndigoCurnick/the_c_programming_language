#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLEN 1000

int get_line_pointer(char *line, int max_len);
void itoa_pointer(int n, char *s);
int atoi_pointer(char *s);
void str_reverse_pointer(char *s, int index, int size);

void exercise_5_6()
{
    printf("This problem will show off some pointer implementations of common C functions\n");
    printf("First we'll show `get_line`\n");
    char c[MAXLEN];

    int len = get_line_pointer(c, MAXLEN);

    printf("%s\n", c);

    printf("Now we will reverse it in place\n");

    str_reverse_pointer(c, 0, len - 1);

    printf("%s\n", c);

    printf("Now we will convert the number `-100` into a string\n");

    int num = -100;

    char s[MAXLEN];
    itoa_pointer(num, s);

    printf("%s\n", s);

    printf("We will now conver the character array `-100` into an integer\n");

    int res = atoi_pointer(s);

    printf("%d\n", res);
}

int get_line_pointer(char *line, int max_len)
{
    int c, i;

    for (i = 0; i < max_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        *line = c;
        line++;
    }

    if (c == '\n')
    {
        *line = c;
        ++i;
    }

    *line = '\0';

    return i;
}

int atoi_pointer(char *s)
{
    int val;

    for (; isspace(*s); s++)
    {
        ;
    }

    int sign = (*s == '-') ? -1 : 1;

    if (*s == '+' || *s == '-')
    {
        s++;
    }

    for (val = 0; isdigit(*s); s++)
    {
        val = 10 * val + (*s - '0');
    }

    return sign * val;
}

void itoa_pointer(int n, char *s)
{
    int sign = n;

    char *original = s;

    do
    {
        *s = abs(n % 10) + '0';
        s++;
    } while (n /= 10);

    if (sign < 0)
    {
        *s = '-';
        s++;
    }

    *s = '\0';

    int s_len = s - original;

    str_reverse_pointer(original, 0, s_len);
}

void str_reverse_pointer(char *s, int index, int size)
{
    char tmp = *(s + index);

    *(s + index) = *(s + (size - index - 1));
    *(s + (size - index - 1)) = tmp;

    if (index >= size / 2 - 1)
    {
        return;
    }

    str_reverse_pointer(s, index + 1, size);
}