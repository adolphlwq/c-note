/* page 47 3.3 else if statement */
#include <stdio.h>

/* page 47 binsearch: find x in v */
int binsearch(int x, int v[], int n){
    int low, high, mid;
    low=0;
    high = n-1;

    while(low<=high){
        mid=(low+high)/2;
        if (x>v[mid])
            low=mid+1;
        else if(x<v[mid])
            high=mid-1;
        else
            return mid;
    }

    return -1;
}

/* page exercise 3.1 */
/* ex_3.1: exsrcise 3.1 */
int ex_31(int x, int v[], int n){
    int low, high, mid;
    low=0;
    high=n-1;
    mid=(low+high)/2;

    while(low<=high && x!=v[mid]){
        if(v[mid]>x)
            high=mid-1;
        else
            low=mid+1;
        mid=(low+high)/2;
    }

    if(x==v[mid])
        return mid;

    return -1;
}

void main(void){
    int v[] = {1,2,3,4,5,6,7};
    printf("position is %d\n", ex_31(3, v, 7));
}