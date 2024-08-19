#include <stdio.h>

#define WORDMAX 15

void exercise_1_13()
{

    int c;
    int lengths[WORDMAX];

    for (int i = 0; i < WORDMAX; i++)
    {
        lengths[i] = 0;
    }

    int buffer = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n')
        {
            ++lengths[buffer];
            buffer = 0;
        }
        else
        {
            ++buffer;
        }
    }

    for (int i = 0; i < WORDMAX; i++)
    {
        printf("%d", i);
        for (int j = 0; j < lengths[i]; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}