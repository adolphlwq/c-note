/* page 17 1.7 Functions */
#include <stdio.h>

/* Declarations function */
int power(int m, int n);

/* page 18 简单的求幂计算函数 */
int power(int m, int n){
    int sum = 1;
    for(int i=0; i<n; i++){
        sum *= m;
    }

    return sum;
}

/* page 19 练习 1.15 使用函数重新编写1.2中的温度转换函数 */
float fahr_to_cel(float temp){
    return (5.0/9.0)*(temp-32.0);
}

void main(void){
    for(int i=0; i<10; i++){
        printf(" 2\tpower %-4d is\t%-4d\n", i, power(2, i));
        printf("-2\tpower %-4d is\t%-4d\n", i, power(-2, i));
    }
}