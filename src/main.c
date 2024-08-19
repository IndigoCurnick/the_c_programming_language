#include "chapter1.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <integer> <integer>\n", argv[0]);
        printf("Usage: %s <chapter> <exercise>\n", argv[0]);
        printf("Please provide chapter number and exercise number");
        return 1;
    }

    int chapter = atoi(argv[1]);
    int exercise = atoi(argv[2]);

    chapter1(exercise);

    return 0;
}