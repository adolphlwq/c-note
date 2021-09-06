/* page 37 2.9 Increment and Decrement Operator */
#include <stdio.h>
#include "chapter02.h"

/* squeeze: 从字符串s中删除字符c */
void squeeze(char s[], int c){
    int i,j;

    for(i=j=0;s[i]!='\0';i++){
        if(s[i]!=c)
            s[j++]=s[i];
    }

    s[j]='\0';
}

/* page 38 strcat: 将字符串t链接到字符串s后面，s必须有足够的空间 */
void my_strcat(char s[], char t[]){
    int i,j;

    i=j=0;
    while(s[i]!='\0')
        i++;
    while((s[i++]=t[j++])!='\0')
        ;
}

/* squeeze_ex24: 将s1中任何与s2中匹配的字符都删除 */
void squeeze_ex24(char s1[], char s2[]){
    int i, j, k;

    for(i=k=0; s1[i]!='\0'; i++){
        for(j=0; s2[j] != '\0' && s2[j]!=s1[i]; j++)
            ;
        if(s2[j] == '\0')
            s1[k++]=s1[i];
    }

    s1[k] = '\0';
}

/* page 38 exercise 2.5 any: return first location in s1 where any char from s2 occurs */
int any(char s1[], char s2[]){
    int i, j;

    for(i=0; s1[i]!='\0'; i++){
        for(j=0; s2[j]!='\0'; j++)
            if(s1[i]==s2[j])
                return i;
    }

    return -1;
}


int main(){
    // char s[] = "warwning: w";
    // squeeze(s, 'w');
    // printf("s is %s\n", s);

    // my_strcat(s, "|abc");
    // printf("strcat s is %s\n", s);

    // char s1[] = "adolphlwq";
    // char s2[] = "lwq";
    // squeeze_ex24(s1, s2);
    // printf("s1 is %s\n", s1);

    printf("%d\n", any("adolphlwq", "lwq"));
}