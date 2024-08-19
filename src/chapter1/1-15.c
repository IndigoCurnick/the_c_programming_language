#include <stdio.h>

float c_to_f(int c);

void exercise_1_15()
{
    // C to F

    printf("Celsius to Fahrenheit\n");
    printf("c\tf\n");

    for (int celsius = 150; celsius >= -20; celsius = celsius - 15)
    {
        printf("%3d\t%6.1f\n", celsius, c_to_f(celsius));
    }
}

float c_to_f(int c)
{
    return ((9.0 / 5.0) * c) + 32.0;
}