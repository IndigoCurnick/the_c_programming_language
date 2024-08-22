#include "chapter2.h"
#include <stdio.h>

void chapter2(int exercise)
{
    switch (exercise)
    {
    case 1:
        exercise_2_1();
        break;
    case 2:
        exercise_2_2();
        break;
    case 3:
        exercise_2_3();
        break;
    case 4:
        exercise_2_4();
        break;
    case 5:
        exercise_2_5();
        break;
    case 6:
        exercise_2_6();
        break;
    case 7:
        exercise_2_7();
        break;
    case 8:
        exercise_2_8();
        break;
    case 9:
        exercise_2_9();
        break;
    case 10:
        exercise_2_10();
        break;
    default:
        printf("Unkown exercise\n");
        break;
    }
}