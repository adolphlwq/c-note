/* page 137 7.4 Formated Input */
#include <stdio.h>

void cal()
{
    double sum, v;
    sum = 0.0;
    while(scanf("%lf", &v) == 1)
        printf("\t%.2f\n", sum += v);
}

void main()
{
    // cal();

    /* read 25 Dec 2018 */
    int day, year;
    char monthname[20];
    scanf("%d %s %d", &day, monthname, &year);
    printf("%d %s %d\n", day, monthname, year);
}