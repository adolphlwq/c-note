/* page 136 Formated Output */
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100     /* max number of chars in one line */
#define OCTLEN 6        /* length of an octal value */

/* print arbitrary input in a sensible way */
void ex_0702()
{
    int c, pos;
    int inc(int pos, int n);

    pos = 0;    /* position in the line */
    while((c = getchar()) != EOF)
        if(iscntrl(c) || c == ' '){
            pos = inc(pos, OCTLEN);
            printf(" \\%03o ", c);

            if(c == '\n'){
                pos = 0;
                putchar(c);
            }
        }else{
            pos = inc(pos, 1);
            putchar(c);
        }
}

/* inc: increment position counter for output */
int inc(int pos, int n)
{
    if(pos+n<MAXLINE)
        return pos+n;
    else{
        putchar('\n');
        return n;
    }
}

void main()
{
    // printf("%.*s", 5, "addddbd");
    ex_0702();
}