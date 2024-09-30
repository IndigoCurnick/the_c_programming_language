#include <stdio.h>

static int daytab0[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int daytab1[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static int *daytab[] = {daytab0, daytab1};

int day_of_year_pointer(int year, int month, int day);
void month_day_pointer(int year, int yearday, int *pmonth, int *pday);
int is_leap_pointer(int year);

void exercise_5_9()
{
    int doy = day_of_year_pointer(2024, 9, 5);

    printf("September 5th 2024 is the %d day of the year\n", doy);

    int pmonth;
    int pday;

    month_day_pointer(2023, 95, &pmonth, &pday);

    printf("The 95th day of 2024 is the %dth month and the %dth day\n", pmonth, pday);
}

int day_of_year_pointer(int year, int month, int day)
{
    int i, leap;

    leap = is_leap_pointer(year);

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

void month_day_pointer(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = is_leap_pointer(year);

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

int is_leap_pointer(int year)
{
    return year & 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
