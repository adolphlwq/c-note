#include <stdio.h>
#include <string.h>

#include "calc.h"

static char buf[BUFSIZE];
static int bufp = 0;       /* next position in buf */

int getch(void){
    return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c){
    if(bufp>=BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* ungets: push string back into the input */
void ungets(char s[])
{
    int len = strlen(s);
    while(len>0)
        ungetch(s[--len]);
}