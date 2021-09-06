/* chapter 4.1 Functions and Program Structure */
#include <stdio.h>
#include <string.h>

#include "chapter04.h"

/* 4.1 Basics of Functions */
int get_line(char line[], int max);
int strindex(char source[], char search[]);
int strrindex(char source[], char search[]);
int strrindex2(char source[], char search[]);

char pattern[] = "ould";

/* get_line: save line to line and return line length */
int get_line(char line[], int max){
    int c, i;
    i=0;
    while(--max>0 && (c=getchar())!=EOF && c!='\n')
        line[i++] = c;
    if(c=='\n')
        line[i++]='\n';
    
    line[i] = '\0';

    return i;
}

/* strindex: return index of t in s */
int strindex(char s[], char t[]){
    int i, j, k;

    for(i=0;s[i]!='\0';i++){
        for(j=i, k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
            ;
        if(k>0 && t[k] == '\0')
            return i;
    }

    return -1;
}

/* findline: find all line container pattern s */
int findline(char line[]){
    int found = 0;

    while(get_line(line, MAXLINE)>0)
        if(strrindex(line, pattern) >= 0){
            printf("%s\n", line);
            found++;
        }
    
    return found;
}

/* page 60 exercise 4.1 */
/* strrindex: returns rightmost index of t in s, -1 if none */
int strrindex(char s[], char t[]){
    int i, j, k, pos;
    pos=-1;

    for(i=0; s[i]!='\0'; i++){
        for(j=i, k=0; t[j]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if(k>0 && t[k] == '\0')
            pos=i;
    }

    return pos;
}

/* strrindex: version2 */
int strrindex2(char s[], char t[]){
    int i, j, k;

    for(i=strlen(s)-strlen(t); i>=0; i--){
        for(j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if(k>0 && t[k] == '\0')
            return i;
    }

    return -1;
}

void main(void){
    char line[MAXLINE];
    printf("find %d line.", findline(line));
}