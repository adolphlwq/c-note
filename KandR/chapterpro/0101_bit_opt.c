/*
位运算练习
参考：https://blog.csdn.net/fsx2550553488/article/details/78965322
*/
#include <stdio.h>

/* 给定一个整数a，设置a的第三位为1 */
void test1(){
    int a = 0b11100101;
    printf("origin a: 0x%X\n", a);
    a |= 1<<3;
    printf("dest a: 0x%X\n", a);
}

/* 给定一个整型数a，清除a的bit5，保证其他位不变 */
void test2()
{
    int a = 0b11111011;
    printf("origin a: 0x%X\n", a);
    a &= ~(1<<5);
    printf("dest a: 0x%X\n", a);
}

/* 给定一个整形数a，取出a的bit3~bit5 */
void test3()
{
    int a = 0b11011011;
    printf("origin a: 0x%X\n", a);
    a >>= 2;
    a &= 0x0F;
    printf("dest a: 0x%X\n", a);
}


void main()
{
    test3();
}