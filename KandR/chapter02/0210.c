/* page 40 2.10 Assignment Operator and Expression */
#include <stdio.h>

/* bitcount: 统计x中值为1的二进制位个数 */
int bitcount(unsigned x){
    int b;
    for(b=0; x!=0; x>>=1) // x&=(x-1)
        if(x&01)
            b++;
    
    return b;
}

int main(){
    printf("%d\n", bitcount(5));
}