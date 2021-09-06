#include <stdio.h>
#include "chapter1.h"

/* page 25 exercise 1.22 将输入行折成短一些的两行或多行。折行位置在第n列之前的
最后一个非空格之后。要能智能处理输入行很长以及在指定的列前没有空格或制表符的情况 */
char line[MAX_COL];

int exptab(int pos);
int findblank(int pos);
int newpos(int pos);
void printl(int pos);

void ex_122(){
    int c, pos;
    pos=0;

    while((c=getchar())!=EOF){
        line[pos]=c;
        if(c=='\t')
            pos=exptab(pos); // ?
        else if(c=='\n'){
            printl(pos); // print current input line
            pos=0;
        }else if (++pos >= MAX_COL){
            pos=findblank(pos);
            printl(pos);
            pos=newpos(pos);
        }
    }
}

/* printl: print line until pos column */
void printl(int pos){
    int i;
    for(i=0;i<pos;i++)
        putchar(line[i]);
    if(pos>0)
        putchar('\n');
}

/* exptab: expand tab into blanks */
int exptab(int pos){
    line[pos]=' ';
    for(++pos;pos<MAX_COL&&pos%MAX_COL!=0;pos++)
        line[pos]=' ';
    if(pos<MAX_COL)
        return pos;
    else{
        printl(pos);
        return 0;
    }
}

/* findblank: find blank's position */
int findblank(int pos){
    while(pos>0 && line[pos]!=' ')
        pos--;
    if(pos==0)
        return MAX_COL;
    else
        return pos+1;
}

/* newpos: rearrange line with new position */
int newpos(int pos){
    int i,j;
    if(pos<=0 || pos>=MAX_COL)
        return 0;
    else{
        i=0;
        for(j=pos;j<MAX_COL;j++){
            line[i]=line[j];
            i++;
        }
        return i;
    }
}

void main(void){
    ex_122();
}