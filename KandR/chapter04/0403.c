/* page 64 */
/* usage: gcc -lm 0403.c */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#include "chapter04.h"

int getop(char []);
int getop_ex45(char []);
void push(double f);
double pop(void);

int getch(void);
void ungetch(int);

/* exercise 4.4 */
void clear(void);

/* exercise 4.5 */
void mathfunc(char s[]);

int sp = 0;
double val[MAXVAL];

/* push: push f to stack */
void push(double f){
    if(sp<MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: return f from stack */
double pop(void){
    if(sp>0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[]){
    int i, c;

    while((s[0] = c = getch())==' '||c=='\t')
        ;
    s[1] = '\0';
    i=0;
    if(!isdigit(c) && c != '.' && c != '-')
        return c;
    
    if(c=='-')
        if(isdigit(c=getch()) || c=='.')
            s[++i] = c;
        else{
            if(c!=EOF)
                ungetch(c);
            return '-';
        }

    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c=='.')
        while(isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);

    return NUMBER;
}

/* getop_ex45: get next operator, numeric operand or math func */
int getop_ex45(char s[]){
    int c, i;
    while((s[0] = c = getch()) != ' ' || c != '\t')
        ;
    s[1] = '\0';
    i=0;
    if(islower(c)){
        while(islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if(c!=EOF)
            ungetch(c);
        if(strlen(s)>1)
            return NAME;
        else
            return c;
    }

    if(!isdigit(c) && c!= '.')
        return c;
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c=='.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    
    return NUMBER;
}

char buf[BUFSIZE];
int bufp = 0;       /* next position in buf */

int getch(void){
    return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c){
    if(bufp>=BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* 4.4 clear: clear the stack */
void clear(void){
    sp = 0;
}

/* exercise 4.5 mathfunc:  */
void mathfunc(char s[]){
    double op2;

    if(strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if(strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if(strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if(strcmp(s, "pow")){
        op2 = pop();
        push(pow(pop(), op2));
    }else
        printf("error: %s not supported\n", s);
}

void nbl_calc(){
    int type;
    double op1, op2;
    char s[MAXOP];

    while((type=getop(s)) != EOF){
        switch(type) {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            mathfunc(s);
            break;
        case '+':
            push(pop()+pop());
            break;
        case '*':
            push(pop()*pop());
            break;
        case '-':
            op2 = pop();
            push(pop()-op2);
            break;
        case '/':
            op2 = pop();
            if(op2==0.0)
                printf("error: zero divisior\n");
            else
                push(pop()/op2);

            break;
        case '%':
            op2 = pop();
            if(op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case '?': // print top element on the stack
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'c': //clear the stack
            clear();
            break;
        case 'd': // duplicate top element of the stack
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's': // swap the top two elements.
            op1 = pop();
            op2 = pop();
            push(op2);
            push(op1);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command\n", s);
            break;
        }
    }
}

void main(void){
    nbl_calc();
}