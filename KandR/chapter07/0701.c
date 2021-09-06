/* page 133 7.1 Standard Input/Output */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void echo()
{
    int c;
    while((c = getchar()) != EOF)
        putchar(c);
}

void my_tolower()
{
    int c;
    while((c = getchar()) != EOF)
        putchar(tolower(c));
}

/* exercise 7.1 */
void ex_0701(char *argv[])
{
    int c;
    if(strcmp(argv[0], "lower") == 0)
        while((c = getchar()) != EOF)
            putchar(tolower(c));
    else
        while((c = getchar()) != EOF)
            putchar(toupper(c));
}

void main(int argc, char *argv[])
{
    // echo();
    // my_tolower();
    ex_0701(argv);
}