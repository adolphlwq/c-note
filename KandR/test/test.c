#include <stdio.h>
#include <string.h>

void test1()
{
    char *s[] = {
        "./a.out", "Adolph", "LWQ"
    };
    printf("%d\n", s);
    printf("%s\n", *s);
    printf("%s\n", ++s[0]);
    printf("%s\n", *s);
}

void test2()
{
    int n = 12;
    n = n^0177;

    printf("n is %d\n", n);
}

void print_bin(int n)
{
    // while(n){
    //     if(n&1)
    //         printf("1");
    //     else
    //         printf("0");
    //     n = n>>1;
    // }

    // printf("\n");
}

void test3(){
    char *p = "abd";
    printf("%s\n", p);
    *(p+1) = 'q';
    printf("%s\n", p);
}

void main()
{
    // test2();
    // print_bin(12);
    // printf("%b", 32);

    // int a;
    // printf("%d\n", sizeof(a));
    // printf("a is %d\n", a);

    test3();
}