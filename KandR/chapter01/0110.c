/* page 22 1.10 External Variables and Scope */
#include <stdio.h>
#include "chapter1.h"

int maxline;
char line[MAX_LINE];
char longest[MAX_LINE];

int get_line(void);
void copy(void);


int get_line(void){
    extern char line[];
    int i, c;

    for(i=0; (c=getchar())!=EOF && i<MAX_LINE-1 && c!='\n';i++){
        line[i]=c;
    }

    if(c=='\n'){
        line[i] = '\n';
        i++;
    }
    line[i]='\0';

    return i;
}

void copy(void){
    // extern char line[];
    // extern char longest[];

    int i=0;
    while((longest[i]=line[i]) != '\0')
        i++;
}

int print_longest_line(){
    int len;
    // extern int maxline;
    // extern char longest[];

    maxline=0;
    while((len=get_line())>0){
        if(len>maxline){
            maxline=len;
            copy();
        }
    }

    if(maxline>0)
        printf("%s\n", longest);
}

void main(void){
    print_longest_line();
}