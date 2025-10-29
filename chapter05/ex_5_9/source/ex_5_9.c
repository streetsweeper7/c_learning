/*
 * Versions of the library functions strncpy, strncat,
 * and strcmp which operate on at most the first n
 * characters of their argument strings.
 *
 * Author: John Banda
 * Date: 27 September 2025
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_lib.h"

#define MAXLINES (5000)
#define BUFSIZE  (5000)

static char daytab[2][13] = 
{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    int days_in_year = leap ? 366 : 365;
    
    // Because 0 is an invalid day of the year,
    // we'll return 0 if an invalid monty or day is
    // entered
    if (year < 1 || month < 1 || month > 12 || day < 1 || 
        day > *(*(daytab + leap) + month)
        return 0;

    for (i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    int days_in_year = leap ? 366 : 365;
    
    // Because 0 is an invalid day of the year,
    // we'll return 0 if an invalid monty or day is
    // entered

    int error = 0;

    if (year < 1 || month < 1 || month > 12 || day < 1 || 
        day > days_in_year)
        error = 1;
    
    // quickly exit if the input is erroneous
    for (i = 1; !error && yearday > daytab[leap][i]; i++)
        yearday -= *(*(daytab + leap) + i);


    if (!error)
    {
        *pmonth = i;
        *pday = yearday;
    } else
    {
        *pmonth = 0;
        *pday = 0;
    }
}

/* sort input lines */
int main()
{
    // Test the functions
    return;
}



