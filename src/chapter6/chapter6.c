#include "chapter6.h"
#include <stdio.h>

void chapter6(int exercise, int argc, char *argv[])
{
    switch (exercise)
    {
    case 1:
        exercise_6_1();
        break;
    case 2:
        exercise_6_2(argc, argv);
        break;
    case 3:
        exercise_6_3();
        break;
    case 4:
        exercise_6_4();
        break;
    case 5:
        exercise_6_5();
        break;
    case 6:
        exercise_6_6();
        break;
    default:
        printf("Unkown exercise\n");
        break;
    }
}