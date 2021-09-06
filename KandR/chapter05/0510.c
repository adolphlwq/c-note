/* page 98 5.10 Command-line Arguments */
#include <stdio.h>
#include <string.h>

#include "chapter05.h"

/* page 99 echo: echo input to output */
void echo(int argc, char *argv[])
{
    int i;
    for(i=1; i<argc; i++)
        printf("%s%s", argv[i], (i<argc-1)?" ":"");
    printf("\n");
}

/* echo2: version 2 */
void echo2(int argc, char *argv[])
{
    while(--argc > 0)
        printf("%s%s", *++argv, (argc>1)?" ":"");

    printf("\n");
}

void main(int argc, char *argv[])
{
    // echo2(argc, argv);
    printf("%s\n", argv[0]);
    printf("%c\n", *argv[0]);
    printf("%c\n", *++argv[0]);
    printf("%c\n", (*++argv)[0]);
    printf("%d\n", argv);
}