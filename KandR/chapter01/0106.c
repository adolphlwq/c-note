/* page 15 1.6 Arrrays */
#include <stdio.h>
#include <ctype.h>

#include "chapter1.h"

/* page 15 统计数字、空白符（空格 制表 换行）、其它字符出现的次数 */
void count(){
    int c, nb, no, i;
    nb=no=0;
    int ndigit[10];
    for(i=0;i<10;i++){
        ndigit[i]=0;
    }

    while((c=getchar())!=EOF){
        if(c>='0'&&c<='9')
            ndigit[c-'0']++;
        else if (c==' '||c=='\t'||c=='\n')
            nb++;
        else
            no++;
    }

    printf("count of blank %d, others %d\n", nb, no);
    for(i=0; i<10;i++){
        printf("number of %d is %d\n", i, ndigit[i]);
    }
}

/* page 17 练习1.13 打印输入中单词长度直方图，水平容易，垂直困难 */
void count_horizontal_chart(){
    int c, nc, i, state;
    int len;            /* length of each bar */
    int maxvalue;       /* maxium value for maxvalue */
    int overflow;       /* number of overflow words */
    int wl[MAX_WORD];   /* word length counters */

    state=OUT;
    nc=0;               /* number of charts in a word */
    overflow = 0;       /* number of words >= MAX_WORD */
    for(i=0; i<MAX_WORD;i++){
        wl[i] = 0;
    }

    while((c=getchar())!=EOF){
        if(c==' '||c=='\t'||c=='\n'){
            state=OUT;
            if(nc>0){
                if (nc < MAX_WORD)
                    wl[nc]++;
                else
                    overflow++;
            }
            nc=0;
        }else if (state == OUT){
            state = IN;
            nc=1;
        }else
            nc++;       /* inside a word */
    }

    maxvalue = 0;
    /* find max value */
    for(i=1;i<MAX_WORD;i++){
        if (wl[i] > maxvalue)
            maxvalue=wl[i];
    }

    for(i=1; i<MAX_WORD;i++){
        printf("%5d - %5d : ", i, wl[i]);
        if(wl[i]>0){
            if ((len = wl[i]*MAX_HIST/maxvalue) <=0)
                len=1;
        }else
            len=0;
        len=wl[i];
        while(len>0){
            putchar('*');
            len--;
        }
        putchar('\n');
    }

    if(overflow>0)
        printf("There are %d words >= %d\n", overflow, MAX_WORD);
}

void count_vertical_chart(){
    int c, nc, state, i, j;
    int maxvalue;
    int overflow;
    int wl[MAX_WORD];

    nc=0;
    state=OUT;
    overflow=0;
    for(i=0; i<MAX_WORD; i++){
        wl[i]=0;
    }

    while((c=getchar())!=EOF){
        if (c==' '||c=='\t'||c=='\n'){
            state=OUT;
            if(nc>0)
                if(nc<MAX_WORD)
                    wl[nc]++;
                else
                    overflow++;
            nc=0;
        }else if(state==OUT){
            state = IN;
            nc=1;
        }else
            nc++;
    }

    // find maxvalue
    maxvalue=0;
    for(i=1; i<MAX_WORD; i++){
        if (maxvalue<wl[i])
            maxvalue=wl[i];
    }

    for(i=MAX_HIST;i>0; i--){
        for(j=1; j<MAX_WORD; j++){
            if ((wl[j]*MAX_HIST/maxvalue)>=i)
                printf("  *  ");
            else
                printf("     ");
        }
        putchar('\n');
    }

    for(i=0;i<MAX_WORD;i++){
        printf("%2d ", wl[i]);
    }

    putchar('\n');
    if(overflow)
        printf("There are %d words > %d", overflow, MAX_WORD);

}

/* page 17 练习1.14 打印输入字符频度直方图 */
void freq_horizontal_chart(){
    int i, c;
    int cc[MAX_CHAR];
    int len, maxvalue;

    for(i=0; i<MAX_CHAR;i++){
        cc[i] = 0;
    }

    while((c=getchar())!=EOF){
        if(c<MAX_CHAR)
            cc[c]++;
    }

    maxvalue=0;
    for(i=0;i<MAX_CHAR;i++){
        if (cc[i]>maxvalue)
            maxvalue=cc[i];
    }

    for(i=0; i<MAX_CHAR;i++){
        if(isprint(i))
            printf("%5d - %c - %5d : ", i, i, cc[i]);
        else
            printf("%5d -   - %5d : ", i, cc[i]);
        if(cc[i]>0){
            if((len=cc[i]*MAX_HIST/maxvalue)<=0)
                len=1;
        }else
            len=0;
        
        while(len>0){
            putchar('*');
            len--;
        }
        putchar('\n');
    }
}

void main(void){
    // count();
    // count_horizontal_chart();
    // count_vertical_chart();
    freq_horizontal_chart();
}