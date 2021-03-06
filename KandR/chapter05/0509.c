/* page 97 5.9 Pointers vs Multi-dimesional Arrays */
#include <stdio.h>

/* exercise 5.9 */
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month and day */
int day_of_year(int year, int month, int day)
{
    int leap;
    char *p;

    leap = year % 4 == 0 && year %100 != 0 || year % 400 == 0;
    p = daytab[leap];
    while(--month)
        day += *++p;    /* first ++ and then *, skip 0 */

    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    char *p;

    leap = year % 4 == 0 && year %100 != 0 || year % 400 == 0;
    p = daytab[leap];
    while(yearday > *++p)
        yearday -= *p;
    
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}

void main(void)
{
    int pm, pd;
    pm = 0;
    pd = 0;

    month_day(2018, 235, &pm, &pd);
    printf("%d\n", day_of_year(2018, 12, 22));
    printf("%d %d\n", pm, pd);
}