/* 4.10 Decusion */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* printd: print decimal number */
void printd(int n){
    if(n<0){
        putchar('-');
        n = -n;
    }
    if(n/10)
        printd(n/10);
    putchar(n%10+'0');
}

/* swap: swap v[i] and v[j] */
void swap(int v[], int i, int j){
    int tmp;
    tmp = v[j];
    v[j] = v[i];
    v[i] = tmp;
}

/* my_qsort: sort v[]  in increment order */
void my_qsort(int v[], int left, int right){
    int i, last;
    if(left>=right)
        return;
    
    swap(v, left, (left+right)/2);
    last = left;
    for(i=left+1;i<=right;i++){
        if(v[i]<v[left])
            swap(v, i, ++last);
    }
    swap(v, left, last);
    my_qsort(v, left, last-1);
    my_qsort(v, last+1, right);
}

/* page 75 exercise 4.12 */
/* itoa: convert n to characters in s */
/* have problem */
void itoa(int n, char s[]){
    static int i;

    if(n/10)
        itoa(n/10, s);
    else{
        i = 0;
        if(n<0)
            s[i++] = '-';
    }

    s[i++] = abs(n)%10 + '0';
    s[i] = '\0';
}

/* exercise 4.13 */
/* reverse: reverse string s in place */
void reverse(char s[]){
    void reverser(char s[], int i, int len);
    reverser(s, 0, strlen(s));
}

/* reverser: reverse string s in place, recursive */
void reverser(char s[], int i, int len){
    int c, j;
    j = len - (i+1);
    if(i<j){
        c = s[i];
        s[i]=s[j];
        s[j] = c;
        reverser(s, ++i, len);
    }
}

void main(void){
    // printd(-123);

    // int v[] = {7,6,5,4,3,2,1};
    // my_qsort(v, 0, 7);
    // for(int i=0; i<7; i++){
    //     printf("%d ", v[i]);
    // }

    // char s[] = "";
    // itoa(-12, s);
    // printf("%s\n", s);

    char s[] = "adolphlwq";
    reverse(s);
    printf("%s\n", s);
}