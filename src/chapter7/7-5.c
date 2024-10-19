#include <stdio.h>

#define MAXLINE 100

static void calculate(float f1, float f2, char op);
static int get_line(char line[], int max_line_len);

void exercise_7_5()
{
    char line[MAXLINE];
    int len;

    float f1;
    float f2;
    char op;

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        int s = sscanf(line, "%f %f %c", &f1, &f2, &op);
        calculate(f1, f2, op);
    }
}

static void calculate(float f1, float f2, char op)
{
    switch (op)
    {
    case '+':
        printf("%f\n", f1 + f2);
        break;
    case '-':
        printf("%f\n", f1 - f2);
        break;
    case '*':
        printf("%f\n", f1 * f2);
        break;
    case '/':
        printf("%f\n", f1 / f2);
        break;
    default:
        printf("Unknown operation\n");
        break;
    }
}

static int get_line(char line[], int max_line_len)
{
    int c, i;

    for (i = 0; i < max_line_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    line[i] = '\0';

    return i;
}