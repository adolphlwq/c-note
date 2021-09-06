/* page 86 chapter 5.4 Address Arithmetic */
#include <stdio.h>
#include "chapter05.h"

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

/* alloc: return pointer points to n char */
char *alloc(int n)
{
    /* have enough size */
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    }else
        return 0;
}

/* afree: free size of pointer p */
void afree(char *p)
{
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int my_strlen(char *s){
    char *p = s;
    while(*p != '\0')
        p++;
    return p-s; /* why not p-s+1? '\0' not considered as char */
}

// void main(void){
//     char s[] = "AdolphLWQ";
//     printf("%d\n", my_strlen(s));
// }