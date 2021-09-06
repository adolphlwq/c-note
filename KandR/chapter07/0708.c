/* page145 7.8 Miscellaneous Functions */
#include <stdio.h>

/* issupper: return 1(true) if c is an upper case letter */
/* 空间利用率比较高 */
int my_isupper(char c)
{
    putchar(c);
    if(c>='A' && c<='Z')
        return 1;
    else
        return 0;
}

/* macro: 展开宏，没有函数调用，效率高，但是要使用更多的空间 */
/* 用宏还存在一个问题，参数求值两次导致不一致。char *p = "This a",
isupper2(*p++) */
#define isupper2(c) ((c)>='A' && (c) <= 'Z')?1:0

void main()
{
    // char c;
    char *p = "This is AdolphLWQ";
    // for(; *p != '\0'; p++)
    //     printf("%c %d\n", *p, my_isupper(*p));

    while(*p != '\0'){
        printf("%c %d\n", *p, my_isupper(*p));
        p++;
    }
}