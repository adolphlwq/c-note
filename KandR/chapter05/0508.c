/* page 97 5.8 Initialization of Pointer Arrays */
#include <stdio.h>

/* month_name: return month name */
char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    return (n<1 || n>12)?name[0]:name[n];
}

void main(void)
{
    printf("%s\n", month_name(3));
}