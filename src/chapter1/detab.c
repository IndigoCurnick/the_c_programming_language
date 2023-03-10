#include <stdio.h>

#define MAXLINE 1000
#define COLUMN_WIDTH 4

int get_line(char s[], int lim);
void replace_tabs(char to[], char from[], int column_width);

int main()
{
    int len;
    char line[MAXLINE];
    char blank_line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("Made it into the main while loop");
        replace_tabs(blank_line, line, COLUMN_WIDTH);
        printf("%s\n", blank_line);
    }

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void replace_tabs(char to[], char from[], int column_width)
{
    int i = 0; // Used for tracking the FROM array
    int j = 0; // Used for tracking the TO array
    int k = 1; // Used for tracking column width
    printf("Inited vars");
    for (i = 0; from[i] != '\0'; ++i)
    {
        printf("Got inside the for loop");
        if (from[i] == '\t')
        {
            printf("I have entered the tab arm");
            while (k <= 4)
            {
                to[j + k] = ' ';
                ++k;
            }
            j = j + k;
        }
        else
        {
            printf("I have entered the other arm");
            to[j] = from[i];

            printf("%s", from[i]);
            printf("%s", to[j]);

            ++j;
            ++k;
        }

        if (k == 4)
        {
            k = 1;
        }
    }

    to[j + 1] = '\0';
}