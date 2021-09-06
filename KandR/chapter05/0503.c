#include <stdio.h>

/* strlen: return length of string s */
int my_strlen(char *s){
    int n;

    for(n = 0; *s != '\0'; s++)
        n++;
    
    return n;
}

void main(void){
    char s[] = "adolphlwq";
    char ss[] = "zsy";
    char *ps = ss;

    printf("%d \n", my_strlen(s));
    printf("%d \n", my_strlen(s+2));
    printf("%d \n", my_strlen(&s[2]));
    printf("%d \n", my_strlen(ps));
    printf("%d \n", my_strlen("LWQ"));
}