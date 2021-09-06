/* page 39 2.9 Bitwise Operator */
#include <stdio.h>

unsigned getbits(unsigned x, int p, int n){
    return (x>>(p+1-n)) & ~(~0<<n);
}

/* page 40 exercise 2.6 */
/* setbits: set n bits of x at position p with bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y){
    return x & ~(~(~0<<n)) << (p+1-n) |
           (y & ~(~0<<n)) << (p+1-n); 
}

/* page 40 exercise 2.7 */
/* invert: inverts the n bits of x that begin at position p */
unsigned inverts(unsigned x, int p, int n){
    return x ^(~(~0 << n)) << (p+1-n);
}

/* page 40 exercise 2.7 */
/* rightrot: rotate x to the right by n position */
unsigned rightrot(unsigned x, int n){
    int wordlength(void);
    int rbit;

    while(n-- > 0){
        rbit = (x&1) << (wordlength()-1);
        x = x >>1;
        x = x|rbit;
    }

    return x;
}

/* wordlength: computes word length of the machine */
int wordlength(void){
    int i;
    unsigned v = (unsigned) ~0;

    for(i=1; (v=v >> 1)>0; i++)
        ;
    
    return i;
}


void main(void){
    printf("%u\n", getbits(123, 4, 3));
}