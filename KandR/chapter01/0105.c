/* 1.5 Character Input and Output */
#include <stdio.h>

#define IN_SPACE 1
#define NON_BLANK 'a'
#define IN 1
#define OUT 0

/* page 10 file copy */
void file_cppy(){
    int c; // c的类型要足够大，能够存放所有输入和EOF
    while((c=getchar())!=EOF){
        putchar(c);
    }
}

/* page 11 练习 1.7 打印EOF */
void print_eof(){
    printf("EOF is %d\n", EOF);
}

/* page 12 字符计数 */
void character_count(){
    long int count=0;
    while(getchar()!=EOF){
        count++;
    }

    printf("count of character is %d\n", count);
}

void character_count2(){
    double nc; // double 类型可以处理更大的数字
    for(nc=0; getchar()!=EOF;nc++)
        ;
    printf("count of character is %.0f\n", nc);
}

/* page 13 行计数 */
void line_count(){
    long nc=0;
    int c;

    while((c=getchar())!=EOF){
        if (c=='\n')
            nc++;
    }

    printf("count of line is %d\n", nc);
}

/* page 13 练习1.8 编写一个统计空格、制表符与换行符个数的程序 */
void count_ex18(){
    int ns, nt, ne, c;
    ns=nt=ne = 0;
    /* 声明后记得赋值，默认值是空，运行结果很混乱
    error output:
    count of space is -705318175, table is 21873, enter is -705318815
    */

    while((c=getchar()) != EOF){
        if (c==' '){
            ns++;
        }else if (c=='\t'){
            nt++;
        }else if(c=='\n'){
            ne++;
        }
    }

    printf("count of space is %d, table is %d, enter is %d\n", ns, nt, ne);
}

/* page 13 练习1.9 将输入复制到输出，并将连续多个空格用一个空格代替*/
void count_ex19_origin(){
    int c, state;
    state=0;

    while((c=getchar()) != EOF){
        if (c==' ' && !state){
            putchar(c);
            state = IN_SPACE;
        }else if(c==' ' && state){
            continue;
        }else if(c != ' '){
            putchar(c);
            state = 0;
        }
    }
}

void count_ex19_1(){
    int c, lastc;
    lastc = NON_BLANK;

    while((c=getchar()) != EOF){
        if (c != ' '){
            putchar(c);
        }else if (lastc != ' '){
                putchar(c);
        }
        lastc = c;
    }
}

void count_ex19_2(){
    int c, lastc;

    while((c=getchar())!=EOF){
        if(c != ' ' || lastc != ' ')
            putchar(c);
        lastc=c;
    }
}

/* page 13 练习1.10 将输入复制到输出，制表符换成\t 回退符换成\b 反斜杠换成\\ */
void replace_ex110(){
    int c;
    while((c=getchar()) != EOF){
        if (c=='\t'){
            printf("\\t");
        }else if (c==' '){
            printf("\\b");
        }else if (c=='\\'){
            printf("\\\\");
        }else{
            putchar(c);
        }
    }
}

/* page 14 单词计数 wc程序骨干 */
void wc(){
    int c, nl, nw, nc, state;
    state=OUT;
    nl=nw=nc=0;

    while((c=getchar())!=EOF){
        ++nc;
        if (c=='\n'){
            nl++;
        }

        if(c==' '||c=='\t'||c=='\n'){
            state=OUT;
        }else if (state==OUT){
            state = IN;
            nw++;
        }
    }

    printf("line %d, word %d, character %d\n", nl, nw, nc);
}

/* page 15 练习1.12 以每行一个单词的形式打印输入 */
void print_words(){
    int c, state;
    state = OUT;

    while((c=getchar()) != EOF){
        if (c == ' ' || c=='\t'|| c=='\n'){
            if (state==IN){
                printf("\n");
            }
            state = OUT;
            continue;
        }

        putchar(c);
        state=IN;
    }
}

void print_words2(){
    int c, state;
    state=OUT;

    while((c=getchar())!=EOF){
        if (c==' '||c=='\t'||c=='\n'){
            if (state==IN){
                putchar('\n');
                state=OUT;
            }
        }else if(state == OUT){
            putchar(c);
            state=IN;
        }else{
            putchar(c);
        }
    }
}

void main(){
    // file_cppy();
    // print_eof();
    // character_count2();
    // line_count();
    // replace_ex110();
    // wc();
    print_words2();
}