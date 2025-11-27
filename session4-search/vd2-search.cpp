#include <stdio.h>
#include "search.h"

int main(){
    //int a[]={9,1,5,7,10,12,18,20,17,11};
    int a[]={1,3,6,7,9,10,11,12,15,17,18};
    int n = sizeof(a)/sizeof(int);
    int x = 12;
    //int pos = linear_search(a,n,x);
    //int pos = binary_search(a,n,x);
    int pos = binary_search_recursion(a, 0, n-1, x);
    if(pos==-1){
        printf("%d is not found in the array\n",x);
    }else{
        printf("Position of %d: %d\n", x, pos);
    }    
    return 0;
}