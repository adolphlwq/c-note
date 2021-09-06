/* page 25 1.10 execise */
#include <stdio.h>

#include "chapter1.h"

/* page 25 exercise 1.20 把输入中的制表符替换成适当数量的空格，使空格充满到制表符终止的地方
    假设制表符终止的位置固定，每隔n列就出现一个制表符，n应作为变量还是常量？ */
void ex_120(){
    int c;
    while((c=getchar())!=EOF){
        if (c!='\t')
            putchar(c);
        else if(c=='\t'){
            for(int i=0;i<SPACE_NUMBER;i++){
                putchar(' ');
            }
        }
    }
}

void detab(){
    int nb, c, pos;
    nb=0;
    pos=1;
    while((c=getchar())!=EOF){
        if(c=='\t'){
            nb=SPACE_NUMBER-(pos-1)%SPACE_NUMBER;
            while(nb>0){
                putchar(' ');
                pos++;
                nb--;
            }
        }else if (c=='\n'){
            putchar(c);
            pos=1;
        }else{
            putchar(c);
            pos++;
        }
    }
}

/* page 25 exercise 1.21 把空格串替换成最少数量的制表符和空格 */
void entab(){
    int state, c, ns, nt, nb;
    state=OUT;
    ns=0;

    while((c=getchar())!=EOF){
        if (c==' '){
            if(state=OUT){
                state=IN;
            }
            ns++;
        }else if(c=='\n'){
            if(state==IN){
                nt=ns/SPACE_NUMBER; // number of tabs
                nb=ns%SPACE_NUMBER; // number of blanks
                while(nt>0){
                    putchar('\t');
                    nt--;
                }
                while(nb>0){
                    putchar(' ');
                    nb--;
                }
                state=OUT;
            }
            ns=0;
        }else{
            if(state==IN){
                nt=ns/SPACE_NUMBER; // number of tabs
                nb=ns%SPACE_NUMBER; // number of blanks
                while(nt>0){
                    putchar('\t');
                    nt--;
                }
                while(nb>0){
                    putchar(' ');
                    nb--;
                }
                state=OUT;
                ns=0;
            }
            putchar(c);
        }
    }
}

void entab_answer(){
    int nt, nb, pos, c;
    nb=0;

    for(pos=1; (c=getchar())!=EOF;pos++){
        if(c==' '){
            if(pos%SPACE_NUMBER != 0)
                nb++;
            else{
                nb=0;
                nt++;
            }
        } else {
            for(; nt>0;nt--)
                putchar('\t');
            if(c=='\t')
                nb=0;
            else
                for(;nb>0;nb--)
                    putchar(' ');
            putchar(c);
            if(c=='\n')
                pos=0;
            else if(c=='\t')
                pos=pos+(SPACE_NUMBER-(pos-1)%SPACE_NUMBER)-1;
        }
    }
}

void main(){
    // ex_120();
    // detab();
    entab();
    // entab_answer();
}