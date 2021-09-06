/* page 102 exercise 5.10 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "calc.h"

int getop(char []);
void ungets(char []);
void push(double);
double pop(void);

/* reverse Polish calculator; uses command line */
int main(int argc, char *argv[])
{
    char s[MAXOP];
    double op2;

    while(--argc > 0){
        ungets(" ");        /* push end of argument */
        ungets(*++argv);    /* push an argument */
        switch(getop(s)){
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if(op2 != 0.0)
                push(pop()/op2);
            else
                printf("error: zero divisor\n");
            break;
        default:
            printf("error: unknown command %s\n", s);
            argc = 1;
            break;
        }
    }

    printf("\t%.8g\n", pop());
    return 0;
}