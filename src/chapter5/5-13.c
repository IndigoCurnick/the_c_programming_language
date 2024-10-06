#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLINE 1000
#define ALLOC 10000

static char alloc_buf[ALLOC];
static char *alloc_p = alloc_buf;

static char *alloc(int size);
static void afree(char *ptr);
static int is_str_int(char *str);
static int get_line(char line[]);
static void put_line(char *line_ptr);
static void tail(int argc, char *argv[]);

void exercise_5_13(int argc, char *argv[])
{
    tail(argc, argv);
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

static void tail(int argc, char *argv[])
{

    int n = 10;
    int lines = 0;
    int c;
    char *line_ptr[MAXLINES];

    if (argc > 1)
    {
        printf("Error: Too many args\n");
        return;
    }

    if (argc > 0)
    {

        if (argv[0][0] != '-')
        {
            printf("Error: Unknown argument\n");
            return;
        }

        if (!is_str_int(argv[0] + 1))
        {
            printf("Error: Bad arguments\n");
        }

        n = atoi(argv[0] + 1);
    }

    char line[MAXLINE];
    int line_len;

    while (line_len = get_line(line))
    {

        char *alloc_line = alloc(line_len);

        if (alloc_line == NULL)
        {
            printf("Error: Out of memory\n");
            return;
        }

        strcpy(alloc_line, line);

        if (lines >= MAXLINES)
        {
            printf("Error: Too many lines\n");
            return;
        }

        line_ptr[lines] = alloc_line;

        lines++;
    }

    int start_pos = 0;

    if (lines >= n)
    {
        start_pos = lines - n;
    }

    for (int i = start_pos; i < lines; ++i)
    {
        put_line(line_ptr[i]);
    }
}

static int get_line(char line[])
{
    int c;
    int i;

    for (i = 0; i < MAXLINE - 1 && (c = getc(stdin)) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

static void put_line(char *line_ptr)
{

    int i = 0;
    while (*(line_ptr + i) != '\n')
    {
        printf("%c", *(line_ptr + i));
        i++;
    }

    printf("\n");
}

static char *alloc(int size)
{
    if (alloc_buf + ALLOC - alloc_p >= size)
    {
        alloc_p += size;
        return alloc_p - size;
    }

    return NULL;
}

static void afree(char *ptr)
{
    if (ptr >= alloc_buf && ptr < alloc_buf + ALLOC)
    {
        alloc_p = ptr;
    }
}