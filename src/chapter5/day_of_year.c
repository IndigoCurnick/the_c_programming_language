#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
int is_leap(int year);

int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = is_leap(year);

    if (day > daytab[leap][month])
    {
        return -1;
    }

    for (i = 1; i < month; i++)
    {
        day += daytab[leap][i];
    }

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = is_leap(year);

    if ((leap && yearday > 366) || (!leap && yearday > 365))
    {
        *pmonth = -1;
        *pday = -1;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }

    *pmonth = i;
    *pday = yearday;
}

int is_leap(int year)
{
    return year & 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int main()
{
    int doy = day_of_year(2023, 4, 5);

    printf("April 5th 2023 is the %d day of the year\n", doy);

    int pmonth;
    int pday;

    month_day(2023, 95, &pmonth, &pday);

    printf("The 95th day of 2023 is the %dth month and the %dth day\n", pmonth, pday);

    return 0;
}