#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000
#define TABLEN 4

int is_str_int(char *str);
int validate_tab_stop_list(int argc, char *argv[]);
void entab(int argc, char *argv[]);
void detab(int argc, char *argv[]);

void exercise_5_11(int argc, char *argv[])
{
    // assume argv contains `entab` or `detab` in zeroth element followed
    // by increasing list of uint

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

int is_str_int(char *str)
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

void entab(int argc, char *argv[])
{
    // Assume argv only contains custom tab stops

    if (!validate_tab_stop_list(argc, argv))
    {
        printf("Error: Invalid tab stop list\n");
        return;
    }

    int c;
    int arg_pos = 0;
    int line_pos = 1;
    int tab_stop = TABLEN;
    int spaces = 0;
    int custom_tabs = argc;

    while ((c = getchar()) != EOF)
    {
        ++line_pos;

        if (c == ' ')
        {
            ++spaces;

            if (custom_tabs)
            {
                tab_stop = atoi(argv[arg_pos]);
            }

            if (line_pos % tab_stop == 0 && spaces > 1)
            {
                putchar('\t');

                if (custom_tabs)
                {
                    ++arg_pos;
                    --custom_tabs;
                }

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
                arg_pos = 0;
                line_pos = 0;
                custom_tabs = argc;
            }

            putchar(c);
        }
    }
}

void detab(int argc, char *argv[])
{
    // Assume argv only contains custom tab stops

    if (!validate_tab_stop_list(argc, argv))
    {
        printf("Error: Invalid tab stop list\n");
        return;
    }

    int c;
    int arg_pos = 0;
    int line_pos = 1;
    int tab_stop = TABLEN;
    int spaces;
    int custom_tabs = argc;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {

            if (custom_tabs)
            {
                tab_stop = atoi(argv[arg_pos]);
                --custom_tabs;
            }

            spaces = tab_stop - line_pos % tab_stop;

            while (spaces)
            {
                putchar(' ');
                ++line_pos;
                --spaces;
            }
        }
        else
        {

            putchar(c);
            ++line_pos;

            if (c == '\n')
            {
                arg_pos = 0;
                line_pos = 0;
                custom_tabs = argc;
            }
        }
    }
}

int validate_tab_stop_list(int argc, char *argv[])
{
    for (size_t i = 1; i < argc; ++i)
    {
        if (!is_str_int(argv[i]) || (i > 1 && atoi(argv[i - 1]) > atoi(argv[i])))
        {
            return 0;
        }
    }
    return 1;
}