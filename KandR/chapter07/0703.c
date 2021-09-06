/* page 136 7.3 Variable-length argument Lists */
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

void miniprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for(p=fmt; *p; p++){
        if(*p != '%'){
            putchar(*p);
            continue;
        }

        switch (*++p){
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for(sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap);
}

#define LOCALFMT 100
/* ex_0703: minimal printf with variable argument list */
void ex_0703(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int i, ival;
    unsigned uval;
    char localfmt[LOCALFMT];
    double dval;

    va_start(ap, fmt);
    for(p=fmt; *p; p++){
        if(*p!='%'){
            putchar(*p);
            continue;
        }
        
        i=0;
        localfmt[i++] = '%';
        while(*(p+1) && !isalpha(*(p+1)))
            localfmt[i++] = *++p;
        localfmt[i++] = *(p+1);
        localfmt[i] = '\0';

        switch (*++p){
        case 'd':
        case 'i':
            ival = va_arg(ap, int);
            printf(localfmt, ival);
            break;
        case 'x':
        case 'X':
        case 'u':
        case 'o':
            uval = va_arg(ap, unsigned);
            printf(localfmt, uval);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf(localfmt, dval);
            break;
        case 's':
            sval = va_arg(ap, char *);
            printf(localfmt, sval);
            break;
        default:
            printf(localfmt);
            break;
        }
    }
}

void main()
{
    ex_0703("%d %s %f adjfa adlfj \n", 3, "AdolphLWQ", 4.5);
}