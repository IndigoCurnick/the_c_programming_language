#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define LINES_IN_PAGE 66

void iterate_file(FILE *fp, int last);

void exercise_7_8(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        FILE *fp = fopen(argv[i], "r");

        int last = argc == i + 1;

        if (fp == NULL)
        {
            printf("File not found: `%s`", argv[i]);
            return;
        }

        iterate_file(fp, last);
    }
}

void iterate_file(FILE *fp, int last)
{
    char line[256];
    int line_count = 0;

    while (fgets(line, sizeof(line), fp))
    {
        printf("%d: %s", line_count, line);
        line_count++;
    }

    if (!last)
    {
        int lines_in_page = line_count % LINES_IN_PAGE;

        while (lines_in_page < LINES_IN_PAGE)
        {
            printf("\n");
            lines_in_page++;
        }
    }
}