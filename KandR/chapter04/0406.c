/* 4.6 Static Variable */
#include <stdio.h>
#include <ctype.h>
#include "chapter04.h"

/* exercise 4.11 */
int getch(void);

/* getop: get next operator or numeric operand */
int getop(char s[]){
    int c, i;
    static int lastc = 0;

    if(lastc == 0)
        c=getch();
    else{
        c=lastc;
        lastc = 0;
    }

    while((s[0]=c) == ' ' || c == '\t')
        c = getch();
    s[1] = '\0';

    if(!isdigit(c) && c!='.')
        return c;
    
    i=0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c=='.')
        while(isdigit(s[++i] = c = getch()))
            ;
    
    s[i] = '\0';
    if(c !=EOF)
        lastc = c;
    
    return NUMBER;
}