/* page 32 2.6 Relation and Logical Operators */
#include <stdio.h>

/* page33 exercise2.2 不使用&& ||修改循环表达式
for(i=0;i<limit-1 && (c=getchar())!='\n'&&c!=EOF;i++)
 */
void ex_22(){
    enum loop {NO, YES};
    enum loop okloop = YES;

    int i, c, limit;
    i=0;
    limit = 5;

    while(okloop){
        if(i>=limit)
            okloop=NO;
        else if((c=getchar())!='\n')
            okloop = NO;
        else if(c==EOF)
            okloop=NO;
        else{
            printf("c is %c\n", c);
            i++;
        }
    }

    // for(i=0; (i<limit) + ((c=getchar())!='\n')+ (c!=EOF) >=3;i++)
    //     printf("c is %c\n", c);
}

void main(void){
    ex_22();
}