/* 3.6 do-while loop */
#include <stdio.h>
#include <string.h>

#include "chapter03.h"

void reverse(char s[]){
    int i, j;
    char tmp;

    for(i=0, j=strlen(s)-1; i<j;i++, j--){
        tmp=s[j];
        s[j]=s[i];
        s[i]=tmp;
    }
}

/* page 52 itoa: convert n to string */
void itoa(int n, char s[]){
    int i, sign;
    if((sign=n)<0)
        n=-n; // make n positive
    
    i=0;
    do{
        s[i++]=n%10+'0';
    }while((n/=10)>0);

    if(sign<0)
        s[i++]='-';
    s[i] = '\0';

    reverse(s);
}

/* page 53 exercise 3.4 */
void itoa_ex34(int n, char s[]){
    int i, sign;
    
    sign = n;
    i=0;
    do{
        s[i++] = abs(n%10) + '0';
    }while((n/=10)!=0);

    if(sign<0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* page 53 exercise 3.5 */
/* itob: convert n to chatacter in s - base b */
void itob(int n, char s[], int b){
    int i, j, sign;
    if((sign=n)<0)
        n = -n;
    i=0;

    do{
        j=n%b;
        s[i++] = j<=9?j+'0':j+'a'-10;
    }while((n/=b)>0);

    if(sign<0)
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);
}

/* page 53 exercise 3.6 */
void itoa_ex36(int n, char s[], int w){
    int i, sign;
    
    sign = n;
    i = 0;
    do{
        s[i++] = abs(n%10) + '0';
    }while((n/=10)!=0);
    
    if(sign<0)
        s[i++] = '-';

    while(i<w)
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s);
}

int main(void){
    char s[40];
    // itoa_ex34(-123, s);
    itoa_ex36(-123, s, 16);
    printf("s is %s\n",s);
}