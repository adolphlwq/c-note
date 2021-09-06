/* page 20 2.3 Constants */
#include <stdio.h>

/* my_strlen: 库函数 strlen()的简单实现 */
int my_strlen(char s[]){
    int i;

    i=0;
    while(s[i] != '\0')
        i++;
    return i;
}

void main(void){
    printf("len of \"\" is %d\n", my_strlen(""));
}