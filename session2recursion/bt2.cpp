
//Tính tổ hợp chập k của n phần tử: C(n,k)
#include <stdio.h>

int factorial(int n){
    //n >= 0
    if(n==0 || n==1){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}

int C(int n, int k){
    if(k>n){
        return 0;
    }else{
        return factorial(n)/(factorial(k)*factorial(n-k));
    }
}

int main(){
    printf("C(5,2)=%d\n", C(5,2));
    return 0;
}
1