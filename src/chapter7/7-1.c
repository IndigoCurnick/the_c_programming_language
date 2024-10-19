#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000
#define TABLEN 4

static void to_upper();
static void to_lower();

void exercise_7_1(int argc, char *argv[])
{
    // First argument is `entab` or `detab`. Following that,
    // either nothing or -m +n meaning tab stop every n columns, starting at
    // column m.

    if (argc == 0)
    {
        printf("Please select program type - `toupper` or `tolower`\n");
        return;
    }

    if (strcmp(argv[0], "toupper") == 0)
    {
        to_upper(argc - 1, argv + 1);
    }
    else if (strcmp(argv[0], "tolower") == 0)
    {
        to_lower(argc - 1, argv + 1);
    }
    else
    {
        printf("Unknown\n");
    }
}

static void to_upper()
{
    char c;
    while ((c = getchar()) != EOF)
    {

        if (islower(c))
        {
            char d = toupper(c);
            putchar(d);
        }
        else
        {
            putchar(c);
        }
    }
}
static void to_lower()
{
    char c;
    while ((c = getchar()) != EOF)
    {

        if (isupper(c))
        {
            char d = tolower(c);
            putchar(d);
        }
        else
        {
            putchar(c);
        }
    }
}