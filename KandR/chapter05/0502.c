/* 5.2 Pointers and Functions Arguments */
#include <stdio.h>
#include <ctype.h>

#include "chapter05.h"

/* page 82 */
void pointer_array(){
    int n, array[SIZE], getint(int *);
    for(n=0; n<SIZE && getint(&array[n]); n++)
        ;
}

int getch(void);
void ungetch(int);

int getint(int *pn){
    int c, sign;
    while(isspace(c = getch())) // skip space
        ;
    
    if(isdigit(c) && c!= EOF && c!= '+' && c != '-'){
        ungetch(c);
        return 0;
    }

    sign = (c = '-')?-1:1;
    if(c == '+' || c == '-')
        c = getch();
    
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    
    *pn *= sign;
    if(c != EOF)
        ungetch(c);

    return c;
}