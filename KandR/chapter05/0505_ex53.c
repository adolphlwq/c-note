#include <stdio.h>

/* page 92 my_strcat: concatenate t to the end of s; pointer version */
void my_strcat(char *s, char *t)
{
    while(*s)
        s++;
    
    while(*s++ = *t++)
        ;
}

void main(void)
{
    char s[] = "ad";
    char t[] = "AdolphLWQ";
    my_strcat(s, t);

    printf("s is %s\n", s);
}