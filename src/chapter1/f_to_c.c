#include <stdio.h>

int main()
{
    // F to C
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Fahrenheit to Celcius\n");
    printf("f\tc\n");
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    printf("\n");
    // C to F

    // float fahr, celsius;
    // int lower, upper, step;

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
    return 0;
}