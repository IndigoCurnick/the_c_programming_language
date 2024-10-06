#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000
#define TABLEN 4

static int is_str_int(char *str);
static void entab(int argc, char *argv[]);
static void detab(int argc, char *argv[]);

void exercise_5_12(int argc, char *argv[])
{
    // First argument is `entab` or `detab`. Following that,
    // either nothing or -m +n meaning tab stop every n columns, starting at
    // column m.

    if (argc == 0)
    {
        printf("Please select program type - `entab` or `detab`\n");
        return;
    }

    if (strcmp(argv[0], "entab") == 0)
    {
        entab(argc - 1, argv + 1);
    }
    else if (strcmp(argv[0], "detab") == 0)
    {
        detab(argc - 1, argv + 1);
    }
    else
    {
        printf("Unknown\n");
    }
}

static int is_str_int(char *str)
{
    for (size_t i = 0; i < strlen(str); ++i)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

static void entab(int argc, char *argv[])
{
    // Assume argv only contains -m +n or nothing

    int c;
    int line_pos = 1;
    int tab_stop = TABLEN;
    int spaces = 0;
    int m = 0;
    int n = 8;

    if (argc > 3)
    {
        printf("Error: Too many env vars\n");
        return;
    }

    if (argc > 0)
    {
        for (int i = 0; i < argc; i++)
        {
            if (argv[i][0] == '-')
            {
                if (!is_str_int(argv[i] + 1))
                {
                    printf("Error: Not a number argument");
                    return;
                }

                m = atoi(argv[i] + 1);
            }
            else if (argv[i][0] == '+')
            {
                if (!is_str_int(argv[i] + 1))
                {
                    printf("Error: Not a number argument");
                    return;
                }

                n = atoi(argv[i] + 1);
            }
            else
            {
                printf("Error: Unknown argument\n");
                return;
            }
        }
    }

    while ((c = getchar()) != EOF)
    {
        ++line_pos;

        if (c == ' ')
        {
            ++spaces;

            if ((m + ((line_pos - m) / n) * n) % tab_stop == 0 && spaces > 1)
            {
                putchar('\t');

                spaces = 0;
            }
        }
        else
        {
            while (spaces)
            {
                putchar(' ');
                --spaces;
            }

            if (c == '\n')
            {
                line_pos = 0;
            }

            putchar(c);
        }
    }
}

static void detab(int argc, char *argv[])
{
    // Assume argv only contains -m +n or nothing

    int c;
    int pos = 0;
    int tab_stop = TABLEN;
    int spaces;

    int m = 0;
    int n = 8;

    if (argc > 3)
    {
        printf("Error: Too many env vars\n");
        return;
    }

    if (argc > 0)
    {
        for (int i = 0; i < argc; i++)
        {
            if (argv[i][0] == '-')
            {
                if (!is_str_int(argv[i] + 1))
                {
                    printf("Error: Not a number argument");
                    return;
                }

                m = atoi(argv[i] + 1);
            }
            else if (argv[i][0] == '+')
            {
                if (!is_str_int(argv[i] + 1))
                {
                    printf("Error: Not a number argument");
                    return;
                }

                n = atoi(argv[i] + 1);
            }
            else
            {
                printf("Error: Unknown argument\n");
                return;
            }
        }
    }

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            putchar(c);
            pos = 0; // Reset column position at new line
        }
        else if (c == '\t')
        {
            if (pos < m)
            {
                // If we're before m, move to column m
                for (; pos < m; pos++)
                {
                    putchar(' ');
                }
            }
            else
            {
                // Calculate the next tab stop after column m
                int next_tab = m + ((pos - m) / n + 1) * n;
                while (pos < next_tab)
                {
                    putchar(' ');
                    pos++;
                }
            }
        }
        else
        {
            // Print the character normally and increment position
            putchar(c);
            pos++;
        }
    }
}