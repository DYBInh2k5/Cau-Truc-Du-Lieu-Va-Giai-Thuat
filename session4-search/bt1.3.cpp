/*
1.3. Viết hàm find_larger(…) tìm phần tử đầu tiên trong một dãy số nguyên lớn hơn một số nguyên cho trước x. 
Nếu tìm thấy, trả về vị trí của phần tử đó, nếu không, trả về -1.
*/
#include <stdio.h>

int find_larger(int a[], int n, int x){
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
        {
            return i;
        }
        
    }
    return -1;
}

int main(){
    int a[]={9,6,5,7,10,1,18,20,1,11};
    int n = sizeof(a)/sizeof(int);
    int pos = find_larger(a, n, 10);
    printf("Larger position: %d\n", pos);
    return 0;
}