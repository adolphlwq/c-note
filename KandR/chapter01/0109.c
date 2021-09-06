/* page 21 1.9 Character Arrays */
#include <stdio.h>
#include "chapter1.h"

/* page 20 读入程序，打印最长的文本行 */
int get_line(char line[], int maxline);
void copy(char to[], char from[]);

void print_longest_line(){
    int len, max;
    char line[MAX_LINE], longest[MAX_LINE];

    max = 0;
    while((len=get_line(line, MAX_LINE))>0){
        if(len>max){
            max = len;
            copy(longest, line);
        }
    }

    if(max>0)
            printf("%s\n", longest);
}

int get_line(char line[], int maxline){
    int c, i;

    for(i=0; i<maxline-1 && (c=getchar())!=EOF && c!='\n';i++)
        line[i] = c;
    if(c=='\n'){
        line[i] = '\n';
        i++;
    }
    
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[]){
    int i=0;
    while((to[i]=from[i])!='\0')
        i++;
}

/* page 22 练习1.16 修改打印函数，使之可打印任意长度输入行 */
int get_line_ex116(char s[], int limit){
    int c, i, j;
    j=0;

    for(i=0;(c=getchar())!=EOF && c!='\n';i++){
        if(i<limit-2){
            s[j]=c;
            j++;
        }

        if(c=='\n'){
            s[j]=c; // ?
            j++;
            i++;
        }
    }

    s[j] = '\0';
    return i;
}

void print_longest_line_ex116(){
    int len;
    int maxline;
    char line[MAX_LINE], longest[MAX_LINE];

    maxline = 0;
    while((len=get_line_ex116(line, MAX_LINE))>0){
        printf("%d %s\n", len, line);
        if(len > maxline){
            maxline=len;
            copy(longest, line);
        }
    }

    if(maxline>0)
        printf("%s\n", longest);
}

/* page 22 exercise 1.17 打印所有长度大于80的输入行 */
int get_greater_line(char s[], int maxline){
    int c, i;
    for(i=0; (c=getchar())!=EOF && i<maxline-1 && c!='\n';i++){
        s[i] = c;
    }

    if(c=='\n'){
        s[i] = '\n';
        i++;
    }
    s[i] = '\0';
    return i;
}

void print_greater_line_ex117(){
    int len, maxline;
    char line[MAX_LINE];

    maxline=0;
    while((len=get_greater_line(line, MAX_LINE))>0){
        if(len>=MIN_LINE){
            if(len>maxline)
                maxline=len;
            printf("%d %s\n", len, line);
        }
    }
}

/* remove trailing blanks and tabs from character strings */
int remove_empty(char line[]){
    int i=0;
    while(line[i] != '\n')
        i++;
    i--; /* back off from \n */

    while(i>=0 && (line[i] == ' ' || line[i] == '\t'))
        i--;

    if(i>=0){
        i++;
        line[i] = '\n';
        i++;
        line[i] = '\0';
    }

    return i;
}

/* page 22 exercise 1.18 删除行末尾的空格、制表符，删除完全空格的行 */
void print_line_ex118(){
    char line[MAX_LINE];

    while(get_line(line, MAX_LINE)>0){
        if(remove_empty(line)>0)
            printf("%s\n%%", line);
    }
}

/* page 22 exercise 1.19 将输入行的字符顺序颠倒过来 */
int reverse(char line[]){
    int i=0;
    while(line[i]!='\n')
        i++;
    return i;
}

/* reverse array of character */
void reverse2(char line[]){
    int i, j, tmp;
    i=0;

    while(line[i]!='\0')
        i++;
    i--;
    if(line[i] == '\n')
        i--;

    for(j=0;j<i;j++){
        tmp=line[i];
        line[i] = line[j];
        line[j]=tmp;
        i--;
    }
}

void print_line_ex119(){
    int tail, i;
    char line[MAX_LINE];
    while(get_line(line, MAX_LINE)>0){
        // tail = reverse(line);
        // for(i=tail;i>=0;i--){
        //     putchar(line[i]);
        // }
        // putchar('\n');
        reverse2(line);
        printf("%s\n", line);
    }
}

void main(void){
    // print_longest_line();
    // print_longest_line_ex116();
    // print_greater_line_ex117();
    // print_line_ex118();
    print_line_ex119();
}