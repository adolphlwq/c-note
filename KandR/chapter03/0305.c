/* page 50 3.5 while and for statement */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 200

/* page 50 atio: version 2 */
int atoi(char s[]){
    int i, n, sign;

    // skip space
    for(i=0;isspace(s[i]); i++)
        ;
    sign = (s[i]=='-')?-1:1;
    if(s[i]=='+'||s[i]=='-')
        i++;

    for(n=0; isdigit(s[i]);i++){
        n=10*n+(s[i]-'0');
    }

    return sign*n;
}

/* page 51 shellsort */
void shellsort(int v[], int n){
    int gap, i, j, temp;

    for(gap=n/2; gap>0;gap/=2){
        for(i=gap;i<n;i++){
            for(j=i-gap; j>=0 && v[j]>v[j+gap];j-=gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}

/* page 51 reverse */
void reverse(char s[]){
    int c, i, j;
    for(i=0,j=strlen(s)-1;i<j; i++,j--){
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

/* exercise 3.3 expand: expand shorthand notation in s1 into string s2*/
void expand(char s1[], char s2[]){
    char c;
    int i, j;

    i=j=0;
    while((c=s1[i++])!='\0'){ /* fetch a char from s1 */
        if(s1[i]=='-' && s1[i+1]>=c){
            i++;
            while(c<s1[i]){
                s2[j++]=c++;
            }
        }else{
            s2[j++]=c;
        }
    }

    s2[j] = '\0';

    printf("format is %s, target is %s\n", s1, s2);
}

void main(void){
    // printf("%d\n", atoi("-34m4"));

    // int v[] = {5,4,3,2,1};
    // shellsort(v, 5);
    // for (int i=0;i<5;i++){
    //     printf("%d ", v[i]);
    // }

    // char s[] = "adolphlwq";
    // reverse(s);
    // printf("%s\n", s);

    // char s1[] = "a-z";
    // char s2[] = "a";
    // expand method can not work!!
    // expand(s1, s2);
    // printf("\ns2 is %s\n", s2);
    char s1[MAXLEN];
    expand("a-z", s1);
    expand("-a-z", s1);
    expand("a-z0-9", s1);
    expand("-a-z0-9", s1);
}