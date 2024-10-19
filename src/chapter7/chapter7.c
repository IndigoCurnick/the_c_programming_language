#include "chapter7.h"
#include <stdio.h>

void chapter7(int exercise, int argc, char *argv[])
{
    switch (exercise)
    {
    case 1:
        exercise_7_1(argc, argv);
        break;
    case 2:
        exercise_7_2();
        break;
    case 3:
        exercise_7_3();
        break;
    case 4:
        exercise_7_4();
        break;
    case 5:
        exercise_7_5();
        break;
    case 6:
        exercise_7_6(argc, argv);
        break;
    case 7:
        exercise_7_7(argc, argv);
        break;
    case 8:
        exercise_7_8(argc, argv);
        break;
    default:
        printf("Unkown exercise\n");
        break;
    }
}