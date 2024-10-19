#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000

void find_pattern(char *pattern, FILE *file_p);

void exercise_7_7(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./c_prog_lang 7 6 pattern file_name\n");
        return;
    }

    char *pat = argv[0];
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        return;
    }

    find_pattern(pat, fp);
}

void find_pattern(char *pattern, FILE *file_p)
{
    size_t line_number = 1;
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, file_p) != NULL)
    {
        if (strstr(line, pattern) != NULL)
        {
            printf("%d: ", line_number);
            printf("%s", line);
        }
        ++line_number;
    }
}