#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void minprintf(char *fmt, ...);

void exercise_7_3()
{
    int d = 11;
    double f = 13.0;
    minprintf("Hello! This is an integer: %d. This is a float: %.3f", d, f);
}

void minprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }

        switch (*++p)
        {
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case '.':
            int n = atoi(++p);
            ++p; // Let's just assumef
            dval = va_arg(ap, double);
            printf("%.*f", n, dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
            {
                putchar(*sval);
            }
            break;
        default:
            putchar(*p);
            break;
        }
    }

    va_end(ap);
}