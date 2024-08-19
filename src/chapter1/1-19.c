#include "chapter1.h"
#include <stdio.h>

#define MAXLINE 1000

void reverse(char to[], char from[], int len);

void exercise_1_19()
{

    char line[MAXLINE];
    char reversed[MAXLINE];
    int len;

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        reverse(reversed, line, len);
        printf("%s\n", reversed);
    }
}

void reverse(char to[], char from[], int len)
{
    int i, j;

    // Check if the last character is a newline, exclude it from the reverse
    if (from[len - 1] == '\n')
    {
        to[len - 1] = '\n'; // Keep the newline at the end
        j = len - 2;        // Start reversing from the second-to-last character
    }
    else
    {
        j = len - 1; // Start reversing from the last character
    }

    // Reverse the characters
    for (i = 0; j >= 0; ++i, --j)
    {
        to[i] = from[j];
    }

    to[i] = '\0'; // Null terminate the reversed string
}