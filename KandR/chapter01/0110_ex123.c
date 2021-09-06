/* page 25 exercise 1.23 删除C语言中所有注释的程序，能正确处理带引号的字符串
与字符常量，C语言中注释不允许嵌套 */
#include <stdio.h>

void rcomment(int c);
void in_comment(void);
void echo_quote(int c);

/* remove all comments from a valid C program */
void ex_123(){
    int c, d;
    while((c=getchar())!=EOF){
        rcomment(c);
    }
}

/* rcomment: read each character, remove the comments */
void rcomment(int c){
    int d;
    if(c=='/')
        if((d=getchar())=='*')
            in_comment();
        else if(d=='/'){
            putchar(c);
            rcomment(d); // digui
        }else{
            putchar(c);
            putchar(d);
        }
    else if(c=='\'' || c=='"')
        echo_quote(c);
    else
        putchar(c);
}

/* in_comment: inside of a valid comment */
void in_comment(void){
    int c,d ;
    c=getchar();
    d=getchar();
    while(c!='*' || d!='/'){
        c=d;
        d=getchar();
    }
}

/* echo_quote: echo character within quetes */
void echo_quote(int c){
    int d;
    putchar(c);
    while((d=getchar())!=c){
        putchar(d);
        if(d=='\\')
            putchar(getchar());
    }

    putchar(d);
}

void main(void){
    ex_123();
}