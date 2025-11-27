/*
1.1. Viết hàm count(…) đếm số lần xuất hiện của một số nguyên trong một dãy số nguyên. 
*/
#include <stdio.h>

int count(int a[], int n, int x){
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]==x){
            c++;
        }
    }
    return c;
}

int main(){
    int a[]={9,1,5,7,10,1,18,20,1,11};
    int n = sizeof(a)/sizeof(int);
    int x = 1;
    printf("Number of %d in the array: %d\n", x, count(a, n, x));
    return 0;
}