#include <stdio.h>

void exercise_1_5()
{
    // C to F

    printf("Celsius to Fahrenheit\n");
    printf("c\tf\n");

    for (int celsius = 150; celsius >= -20; celsius = celsius - 15)
    {
        printf("%3d\t%6.1f\n", celsius, ((9.0 / 5.0) * celsius) + 32.0);
    }
}