#include "chapter8.h"
#include <stdio.h>

void chapter8(int exercise, int argc, char *argv[])
{
    switch (exercise)
    {
    case 1:
        exercise_8_1();
        break;
    case 2:
        exercise_8_2(argc, argv);
        break;
    case 3:
        printf("In progress\n");
        break;
    case 4:
        printf("Not yet implemented\n");
        break;
    default:
        printf("Unkown exercise\n");
        break;
    }
}