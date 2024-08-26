#include "chapter1.h"
#include "chapter2.h"
#include "chapter3.h"
#include "chapter4.h"
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

    switch (chapter)
    {
    case 1:
        chapter1(exercise);
        break;
    case 2:
        chapter2(exercise);
        break;
    case 3:
        chapter3(exercise);
        break;
    case 4:
        chapter4(exercise);
        break;
    default:
        printf("Unknown chapter");
        break;
    }

    return 0;
}