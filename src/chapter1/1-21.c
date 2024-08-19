#include "chapter1.h"
#include <stdio.h>

#define TAB_LENGTH 4
#define MAXLINE 1000

void exercise_1_21()
{
    int len;
    char line[MAXLINE];
    char entabbed[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        int i = 0, j = 0;
        int space_count = 0;

        while (line[i] != '\0')
        {
            if (line[i] == ' ')
            {
                space_count++;

                if (space_count == TAB_LENGTH)
                {
                    entabbed[j++] = '\t';
                    space_count = 0;
                }
            }
            else
            {
                while (space_count > 0)
                {
                    entabbed[j++] = ' ';
                    space_count--;
                }

                entabbed[j++] = line[i];
            }

            i++;
        }

        while (space_count > 0)
        {
            entabbed[j++] = ' ';
            space_count--;
        }

        entabbed[j] = '\0';

        printf("%s", entabbed);
    }
}