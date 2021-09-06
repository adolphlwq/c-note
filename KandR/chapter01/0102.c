/* 1.2 Variable and Expressions */
#include <stdio.h>

#define STEP 20
#define LOWER 0
#define UPPER 300

/* page 4 摄氏度与华摄氏度转换  */
void fahrenheit()
{
    for(int i=LOWER; i<=UPPER; i+=STEP)
    {
        printf("%-6d %-6d \n", i, 5 * (i - 32)/9);
    }
}

void fahrenheit2(){
    int i = LOWER;
    while(i<=UPPER){
        printf("%d \t %d\n", i, 5*(i-32)/9);
        i+=STEP;
    }
}

/* 宽度与精度控制 */
void fahrenheit3(){
    for(int i=LOWER; i<=UPPER; i+=STEP){
        printf("%3d\t%6.1f\n", i, (5.0/9.0)*(i-32));
    }
}

/* page 9 练习 1.5 打印摄氏度对应的华摄氏度 */
void fahrenheit4(){
    for(int i=LOWER; i<=UPPER;i+=STEP){
        printf("%d\t%-6.1f\n", i, (9.0/5.0)*i + 32.0);
    }
}

void final_fahrenheit()
{
    int fahr=0, upper=300;

    while(fahr <= upper)
    {
        printf("%3d %6d \n", fahr, 5*(fahr-32)/9);
        fahr += 20;
    }
}

void float_fahrenheit()
{
    float celsius;
    for(int i=0; i<=300;i+=20)
    {
        celsius = 5*(i-32.0)/9.0;
        printf("%3d %6.1f \n", i, celsius);
    }
}

void reverse_fahrenheit()
{
    for(int i=300;i>=0;i-=20)
    {
        printf("%3d %6.1f\n", i, 5*(i-32)/9.0);
    }
}

void symbolic_fahrenheit()
{
    for(int i=LOWER; i<=UPPER;i+=STEP)
    {
        printf("%3d %6.1f\n", i, 5*(i-32)/9.0);
    }
}

int main(void)
{
    fahrenheit4();
}