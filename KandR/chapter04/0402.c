/* 4.2 */
#include <stdio.h>
#include <ctype.h>
#include "chapter04.h"

/* atof: convert character to double */
double atof(char s[]){
    double val, power;
    int i, sign;

    for(i=0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-')? -1: 1;
    if(s[i] == '+' || s[i]=='-')
        i++;
    for(val=0.0; isdigit(s[i]); i++)
        val=10.0*val+(s[i]-'0');

    if(s[i] == '.')
        i++;

    for(power=1.0; isdigit(s[i]); i++){
        val = 10.0*val + s[i]-'0';
        power = power*10.0;
    }

    return sign*val/power;
}

/* page 61 simple_calculator */
double simple_calculator(){
    double sum;
    char line[MAXLINE];

    sum = 0;
    while(m_get_line(line, MAXLINE)>0)
        printf("\t%g\n", sum+=atof(line));
    
    return 0;
}

/* page 62 exercise 4.2 */
/* atof_ex42: convert string s to double */
double atof_ex42(char s[]){
    double val, power;
    int expp, i, sign;

    for(i=0; isspace(s[i]); i++)
        ;
    sign = (s[i]=='-')? -1: 1;
    if(s[i]=='-'||s[i]=='+')
        i++;

    for(val=0.0; isdigit(s[i]);i++)
        val = 10.0*val+(s[i]-'0');
    if(s[i]=='.')
        i++;

    for(power=1.0; isdigit(s[i]);i++){
        val = 10.0*val+(s[i]-'0');
        power*=10;
    }
    val=sign*val/power;

    if(s[i]=='e'||s[i]=='E'){
        sign=(s[++i]=='-')?-1:1;
        if(s[i]=='+'||s[i]=='-')
            i++;
        for(expp=0;isdigit(s[i]);i++)
            expp=10*expp+(s[i]-'0');
        if(sign==1)
            while((expp-- > 0))
                val*=10;
        else
            while(expp-- > 0)
                val /= 10;
    }

    return val;
}

void main(void){
    // char s[] = "  -3.34";
    // printf("%f\n", atof(s));
    // simple_calculator();
    char s1[]="  -123.41E-5";
    printf("%f\n", atof_ex42(s1));

    printf("test 0.1 not exactly. %f\n", 10.0*0.1);
}