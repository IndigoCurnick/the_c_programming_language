#include "chapter5.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
static int numcmp(const char *, const char *);
static void swap(void *v[], int, int);

static int rev_numcmp(const char *, const char *);
static int rev_strcmp(const char *, const char *);
static int rev(int i);

void exercise_5_14(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;

    if (argc >= 1)
    {

        for (int i = 0; i < argc; ++i)
        {
            if (strcmp(argv[1], "-n") == 0)
            {
                numeric = 1;
            }
            else if (strcmp(argv[1], "-r") == 0)
            {
                reverse = 1;
            }
        }
    }

    int (*num)(const char *, const char *) = reverse ? rev_numcmp : numcmp;
    int (*str)(const char *, const char *) = reverse ? rev_strcmp : strcmp;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        my_qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? num : str));
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

static int rev_numcmp(const char *s1, const char *s2)
{
    int i = numcmp(s1, s1);

    return rev(i);
}

static int rev_strcmp(const char *s1, const char *s2)
{
    int i = strcmp(s1, s2);

    return rev(i);
}

static int rev(int i)
{
    if (i == 0)
    {
        return 0;
    }
    else if (i > 0)
    {
        return -1;
    }
    else if (i < 0)
    {
        return 1;
    }
}