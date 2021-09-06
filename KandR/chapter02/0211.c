/* page 41 2.11 Conditional Expression */
#include <stdio.h>

/* page 41 exercise 2.10 */
/* lower: convert c to lower case (ASCII only) */
int lower(int c){
    return c>='A' && c<='Z'? c+'a'-'A':c;
}

void main(){
    printf("%c\n", lower('S'));
}