
#include <stdio.h>

int factTR(int n, int result=1){
    if(n<=1){
        return result;
    }else{
        return factTR(n-1, n*result);
    }
}

int sumTR(int n, int result=0){
    if(n==0){
        return result;
    }else{
        return sumTR(n-1, n+result);
    }
}


int main(){
    printf("5!=%d\n", factTR(5));
    printf("sum(5)=%d\n", sumTR(5));
    return 0;
}
1