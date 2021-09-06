#include <stdio.h>

#define MAXLINE 1000

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define NAME 'n' /* signal that a new name was found */

#define dprint(expr) printf(#expr " = %d\n", expr)
#define paste(front, back) front ## back

/* exercise 4.14 */
#define swap(t, x, y) { t _z;\
                        _z = y;\
                        y=x;\
                        x=_z;}

int m_get_line(char line[], int max){
    int c, i;
    i=0;
    while(--max>0 && (c=getchar())!=EOF && c!='\n')
        line[i++] = c;
    if(c=='\n')
        line[i++]='\n';
    
    line[i] = '\0';

    return i;
}