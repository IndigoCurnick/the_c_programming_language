#include "chapter2.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXLINE 1000

int htoi(char hex[]);

void exercise_2_3()
{
    char hex[MAXLINE];

    get_line(hex, MAXLINE);

    int dec = htoi(hex);

    if (dec == -1)
    {
        printf("Invalid HEX input");
    }
    else
    {
        printf("Decimal: %d", dec);
    }
}

int htoi(char hex[])
{
    int result = 0;
    int i = 0;
    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
    {
        i = 2;
    }

    while (hex[i] != '\n')
    {
        result *= 16;

        if (hex[i] >= '0' && hex[i] <= '9')
        {
            result += hex[i] - '0'; // Convert '0'-'9' to 0-9
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            result += hex[i] - 'a' + 10; // Convert 'a'-'f' to 10-15
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            result += hex[i] - 'A' + 10; // Convert 'A'-'F' to 10-15
        }
        else
        {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            return -1; // Return an error if an invalid character is found
        }

        ++i;
    }

    return result;
}