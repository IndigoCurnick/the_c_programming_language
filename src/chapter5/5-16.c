#include "chapter5.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000
#define MAXLEN 1000

#define ALLOC 10000

static char *lineptr[MAXLINES];
static char alloc_buf[ALLOC];
static char *alloc_p = alloc_buf;

static char *alloc(int size);
static void afree(char *ptr);

static int readlines(char *lineptr[], int nlines);
static void writelines(char *lineptr[], int nlines);

static void my_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

static void swap(void *v[], int, int);

static int numcmp(const char *, const char *);
static int compare_wrapper(const char *a, const char *b);
static int is_dir_char(char c);
static int compare(const char *s1, const char *s2);

static int numeric = 0;
static int reverse = 0;
static int fold = 0;
static int directory = 0;

void exercise_5_16(int argc, char *argv[])
{
    int nlines;

    if (argc >= 1)
    {
        for (int i = 0; i < argc; i++)
        {
            if (strcmp(argv[i], "-n") == 0)
            {
                numeric = 1;
            }
            else if (strcmp(argv[i], "-r") == 0)
            {
                reverse = 1;
            }
            else if (strcmp(argv[i], "-f") == 0)
            {
                fold = 1;
            }
            else if (strcmp(argv[i], "-d") == 0)
            {
                directory = 1;
            }
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        my_qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))compare_wrapper);
        writelines(lineptr, nlines);
        return;
    }
    else
    {
        printf("Error: Input too large\n");
        return;
    }
}

static void my_qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;

    if (left >= right)
    {
        return;
    }

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if ((*comp)(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    my_qsort(v, left, last - 1, comp);
    my_qsort(v, last + 1, right, comp);
}

static int numcmp(const char *s1, const char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
    {
        return -1;
    }
    else if (v1 > v2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static void swap(void *v[], int i, int j)
{
    void *tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

static int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;

    while ((len = get_line(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
        {
            return -1;
        }
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
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

static int compare_wrapper(const char *a, const char *b)
{
    int result = compare(a, b);
    // If reverse flag is enabled, invert the comparison result
    return reverse ? -result : result;
}

static int is_dir_char(char c)
{
    return isalnum((unsigned char)c) || isspace((unsigned char)c);
}

// Generic comparison function
static int compare(const char *s1, const char *s2)
{
    const char *a = s1;
    const char *b = s2;

    // Handle numeric comparison
    if (numeric)
    {
        return numcmp(a, b);
    }

    // Loop through both strings for comparison
    while (*a != '\n' || *b != '\n')
    {
        // If directory order, skip non-alphanumeric/non-space characters

        if (directory)
        {
            while (*a != '\n' && !is_dir_char(*a))
                a++;
            while (*b != '\n' && !is_dir_char(*b))
                b++;
        }

        // If one string ends, comparison should stop
        if (*a == '\0' || *b == '\0')
        {
            break;
        }
        // Apply case-insensitivity (folding) if necessary
        char c1 = fold ? tolower((unsigned char)*a) : *a;
        char c2 = fold ? tolower((unsigned char)*b) : *b;

        // Compare characters
        if (c1 != c2)
        {
            return c1 - c2;
        }
        // Move to the next characters
        a++;
        b++;
    }

    // Compare the lengths of strings (in case they are prefixes of each other)
    return *a - *b;
}