#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void minscanf(char *fmt, ...);

void exercise_7_4()
{
    int day, month, year;
    minscanf("%d/%d/%d", &day, &month, &year);

    printf("Day: %d\nMonth: %d\nYear: %d", day, month, year);
}

void minscanf(char *fmt, ...)
{
    va_list ap;
    int ch;

    va_start(ap, fmt);
    for (; *fmt != '\0'; fmt++)
    {
        if (*fmt == '%')
        {
            switch (*++fmt)
            {
            case 'd':
                scanf("%d", va_arg(ap, int *));
                break;
            case 'f':
                scanf("%f", va_arg(ap, double *));
                break;
            case 's':
                scanf("%s", va_arg(ap, char *));
                break;
            default:
                break;
            }
        }
        else
        {
            ch = getchar();
            if (ch != *fmt)
            {
                printf("Input format mismatch!\n");
                break;
            }
        }
    }

    va_end(ap);
}