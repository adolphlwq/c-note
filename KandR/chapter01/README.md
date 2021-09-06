# Chapter 1 Tutorial Introduction

## 重要编程题
- page 13 ex1.8 编写一个统计空格、制表符、换行数量的程序
- page 13 ex1.9 编写一个将输入复制到输出的程序，并将连续的空格用一个空格代替

## Compress Blank
注意这里`prev=ch;`每次输出后都要替换。
```C
#include <stdio.h>

void compress_blank()
{
    int prev=1;
    int ch;
    while((ch=getchar()) != EOF)
    {
        if (ch == ' ')
        {
            if (prev != ' ')
                putchar(ch);
                // prev=ch;
        }else{
            putchar(ch);
        }
        prev=ch;
    }
}

void main(void)
{
    compress_blank();
}
```

## Words Count
思路很精妙，代码也很简短。自己很难想出来。
```C
#include <stdio.h>
#define IN 1
#define OUT 0

void count_cc()
{
    int nw, nl, nc, c, state;
    nw=nl=nc=0;
    state = OUT;

    while((c=getchar())!=EOF)
    {
        nc++;
        if(c=='\n')
            nl++;
        if((c==' ')||(c=='\t')||(c=='\n'))
            state=OUT;
        else if(state==OUT)
        {
            state=IN;
            nw++;
        }
    }

    printf("%d lines. %d words. %d chars\n", nl, nw, nc);
}
```