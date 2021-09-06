#include <stdio.h>

/* page 92 exercise 5.4 my_strend: return 1 if string s occurs at the end of s */
int my_strend(char *s, char *t)
{
    char *bs = s;
    char *bt = t;

    while(*s)
        s++;
    while(*t)
        t++;
    
    for(; *s == *t; s--, t--)
        if(t == bt || s == bs)
            break;              /* at the beginning of a str */
    if(*s == *t && t == bt && *s != '\0')
        return 1;
    else
        return 0;
}

void main(void)
{
    char s[] = "abcd";
    char t[] = "cd";

    printf("%d\n", my_strend(s, t));
}