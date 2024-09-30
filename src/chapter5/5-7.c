#include "chapter5.h"
#include <stdio.h>
#include <string.h>

/* Definitions */

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000

/* Statics */
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

/* Globals */
char *lineptr[MAXLINES];

/* Functions */
char *alloc(int n);
int readlines(char *lineptr[], int nlines);
int readlines_fast(char *lineptr[], char *lines, int maxlines, int maxlen);
void writelines(char *lineptr[], int nlines);
void swap_char_ptr(char *v[], int i, int j);
void qsort(char *v[], int left, int right);

void exercise_5_7()
{
    int nlines;
    // if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    // {
    //     qsort(lineptr, 0, nlines - 1);
    //     writelines(lineptr, nlines);
    // }
    // else
    // {
    //     printf("Error: Input too large");
    //     return;
    // }

    char lines[ALLOCSIZE];

    if ((nlines = readlines_fast(lineptr, lines, MAXLINES, ALLOCSIZE)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
    }
    else
    {
        printf("Error: Input too large");
        return;
    }
}

int readlines(char *lineptr[], int maxlines)
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

/*
    lineptr = array of pointers
    lines = all the lines
    maxlines = maximum number of lines i.e. length of lineptr
    maxlen = maximum number of characters i.e. length of lines
 */
int readlines_fast(char *lineptr[], char *lines, int maxlines, int maxlen)
{
    int len, nlines;
    char *p, line[maxlen];

    char *lines_start = lines;
    nlines = 0;

    while ((len = get_line(line, maxlen)) > 0)
    {
        if (nlines >= maxlines || (lines - lines_start + len) > maxlen)
        {
            return -1;
        }
        else
        {
            p = lines;
            line[--len] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            lines += len + 1;
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

void qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right)
    {
        return;
    }

    swap_char_ptr(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
        {
            swap_char_ptr(v, ++last, i);
        }
    }

    swap_char_ptr(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap_char_ptr(char *v[], int i, int j)
{
    char *tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
    {
        return 0;
    }
}