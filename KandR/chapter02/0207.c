/* page 33 2.7 Type Conversions */
#include <stdio.h>
#include "chapter02.h"

/* page 34 将char类型转换成int类型 */
int atoi(char s[]){
    int i,n;
    n=0;
    for(i=0; s[i]>='0'&&s[i]<='9';i++){
        n = 10*n+(s[i]-'0');
    }

    return n;
}

/* lower: 把字符c转换成小写形式，对ASCII字符集有效 */
int lower(int c){
    if(c>='A'&&c<='Z')
        return c+'a'-'A';
    
    return c;
}

/* page 37 exercise 2.3 把十六进制字符串转化成等价的整型值 */
/* htoi: convert hexadecimal string s to integer */
int htoi(char s[]){
    int i, n, hexdigit, inhex;
    i=0;
    if(s[i]=='0'){    //skip optional 0x or 0X
        i++;
        if(s[i]=='X' || s[i]=='x')
            i++;
    }

    n=0;
    inhex=YES;
    for(; inhex ==YES;i++){
        if(s[i]>='0'&&s[i]<='9')
            hexdigit=s[i]-'0';
        else if(s[i]>='a'&&s[i]<='z')
            hexdigit = s[i]-'a'+10;
        else if(s[i]>='A'&&s[i]<='Z')
            hexdigit=s[i]-'A'+10;
        else
            inhex=NO;

        if(inhex==YES)
            n=16*n+hexdigit;
    }

    return n;
}

void main(void){
    printf("3339 to int is %d\n", atoi("3339"));
    printf("%c\n" , lower('A'));

    // test htoi
    printf("htoi(\'0x23\') is %d\n", htoi("0x23"));
}