/* page 92 exercise 5.6 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "chapter05.h"

/* getline: read a line into s, return length */
int my_getline(char *s, int limit)
{
    int c, i;
    i = 0;

    while(i < limit && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
        i++;
    if(c == '\n')
        *s++ = '\n';
    *s = '\0';
    return i;
}

/* my_atoi: convert s to integer; pointer version */
int my_atoi(char *s)
{
    int n, sign;

    for(; isspace(*s); s++)
        ;
    sign = (*s == '-')?-1:1;
    if(*s == '-' || *s == '+')
        s++;

    for(n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    
    return sign*n;
}

void my_reverse(char *s);

/* my_itoa: convert n to character in s; pointer version */
void my_itoa(int n, char *s)
{
    int sign;
    char *t = s;

    if((sign = n) < 0)
        n = -n;
    
    do{
        *s++ = n%10 + '0';
    }while((n/=10) != 0);

    if(sign < 0)
        *s++ = '-';
    *s = '\0';
    my_reverse(t);
}


/* my_reverse: reverse string s in place */
void my_reverse(char *s)
{
    int c;
    char *t;

    for(t = (s+strlen(s) - 1); s < t; s++, t--){
        c = *s;
        *s = *t;
        *t = c;
    }
}

/* my_strindex: return index of t in s, -1 if none */
int my_strindex(char *s, char *t)
{
    char *b = s;
    char *p, *r;

    for(; *s != '\0'; s++){
        for(p=s, r = t; *r != '\0' && *p == *r; p++, r++)
            ;
        if(r > t && *r == '\0')
            return s-b;
    }

    return -1;
}

/* my_atof: convert string s to double; pointer version */
double my_atof(char *s)
{
    double val, power;
    int sign;

    for(; isspace(*s); s++)
        ;
    sign = (*s == '-')?-1:1;

    if(*s == '-' || *s == '+')
        s++;
    for(val = 0.0; isdigit(*s); s++)
        val = 10.0 * val + (*s - '0');
    
    if(*s == '.')
        s++;
    for(power = 10.0; isdigit(*s); s++){
        val = 10.0 * val + (*s - '0');
        power *= 10;
    }

    return sign * val / 10;
}

/*
int getch(void);
void ungetch(int);
/* my_getop: get next operator or numeric oprand; pointer version */
int my_getop(char *s)
{
    int c;
    while((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s+1) = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    
    if(isdigit(c))
        while(isdigit(*++s = c = getch()))
            ;
    if(c == '.')
        while(isdigit(*++s = c = getch()))
            ;
    *s = '\0';

    if(c != EOF)
        ungetch(c);
    
    return NUMBER;
}
*/

void main(void)
{
    // char s[MAXSIZE];
    // my_getline(s, MAXSIZE);

    // printf("s is %s\n", s);

    // printf("%d\n", my_atoi("-123"));

    // char s[MAXSIZE];
    // my_itoa(-123, s);
    // printf("%s\n", s);

    // printf("%d\n", my_strindex("AdolphLWQ", "LWQ"));

    printf("%f\n", my_atof("-3.14"));
    printf("%f\n", my_atof("3.14"));
}