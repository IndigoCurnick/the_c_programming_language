#include <stdio.h>

void exercise_1_4()
{
    // C to F

    float fahr, celsius;
    int lower, upper, step;

    lower = -20;
    upper = 150;
    step = 15;

    celsius = lower;
    printf("Celsius to Fahrenheit\n");
    printf("c\tf\n");
    while (celsius <= upper)
    {
        fahr = ((9.0 / 5.0) * celsius) + 32.0;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}