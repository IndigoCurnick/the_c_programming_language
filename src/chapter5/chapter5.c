#include "chapter5.h"
#include <stdio.h>

void chapter5(int exercise, int argc, char *argv[])
{
    switch (exercise)
    {
    case 1:
        exercise_5_1();
        break;
    case 2:
        exercise_5_2();
        break;
    case 3:
        exercise_5_3();
        break;
    case 4:
        exercise_5_4();
        break;
    case 5:
        exercise_5_5();
        break;
    case 6:
        exercise_5_6();
        break;
    case 7:
        exercise_5_7();
        break;
    case 8:
        exercise_5_8();
        break;
    case 9:
        exercise_5_9();
        break;
    case 10:
        exercise_5_10(argc, argv);
        break;
    case 11:
        exercise_5_11(argc, argv);
        break;
    default:
        printf("Unkown exercise\n");
        break;
    }
}