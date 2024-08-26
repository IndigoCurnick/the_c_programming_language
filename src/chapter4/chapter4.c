#include "chapter4.h"
#include <stdio.h>

void chapter4(int exercise)
{
    switch (exercise)
    {
    case 1:
        exercise_4_1();
        break;
    case 2:
        exercise_4_2();
        break;
    case 3:
        exercise_4_3();
        break;
    case 4:
        exercise_4_4();
        break;
    case 5:
        exercise_4_5();
        break;
    case 6:
        exercise_4_6();
        break;
    case 7:
        exercise_4_7();
        break;
    case 8:
        exercise_4_8();
        break;
    case 9:
        exercise_4_9();
        break;
    case 10:
        exercise_4_10();
        break;
    case 11:
        exercise_4_11();
        break;
    case 12:
        exercise_4_12();
        break;
    case 13:
        exercise_4_13();
        break;
    case 14:
        exercise_4_14();
        break;
    default:
        printf("Unkown exercise\n");
        break;
    }
}