#include "chapter3.h"
#include <stdio.h>

void chapter3(int exercise)
{
    switch (exercise)
    {
    case 1:
        exercise_3_1();
        break;
    case 2:
        exercise_3_2();
        break;
    case 3:
        exercise_3_3();
        break;
    case 4:
        exercise_3_4();
        break;
    case 5:
        exercise_3_5();
        break;
    case 6:
        exercise_3_6();
        break;
    default:
        printf("Unkown exercise\n");
        break;
    }
}