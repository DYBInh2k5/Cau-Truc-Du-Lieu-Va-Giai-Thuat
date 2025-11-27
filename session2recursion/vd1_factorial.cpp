
#include <stdio.h>

int factorial(int n){
    //n >= 0
    if(n==0 || n==1){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}

int fibonacci(int n){
    //n>=0
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int sum(int n){
    if(n==1){
        return 1;
    }else{
        return n+sum(n-1);
    }
}

int main(){
    printf("Factorial: %d\n", factorial(10));
    printf("Un of Fibonacci: %d\n", fibonacci(3));
    printf("Sum: %d\n", sum(3));
    return 0;
}
1