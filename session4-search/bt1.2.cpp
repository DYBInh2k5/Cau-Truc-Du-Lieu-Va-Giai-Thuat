/*
1.2. Viết hàm find_min(…) tìm phần tử đầu tiên nhỏ nhất trong một dãy số nguyên. 
Trả về vị trí của nó trong dãy.
*/
#include <stdio.h>

int find_min(int a[], int n){
    int min_index = 0;
    for(int i=1; i<n; i++){
        if(a[i] < a[min_index]){
            min_index = i;
        }
    }
    return min_index;
}

int main(){
    int a[]={9,6,5,7,10,1,18,20,1,11};
    int n = sizeof(a)/sizeof(int);
    int pos = find_min(a, n);
    printf("Min position: %d\n", pos);
    return 0;
}