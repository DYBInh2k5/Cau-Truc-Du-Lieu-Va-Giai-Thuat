#include <stdio.h>

int isprime1(int n){
    if(n <= 1) return 0;
    for (int i = 2; i < n; i++)
    {
        if(n % i == 0) return 0;
    }
    return 1;
}

int isprime(int n){
    if(n <= 1) return 0;
    for (int i = 2; i*i <= n; i++)
    {
        if(n % i == 0) return 0;
    }
    return 1;
}

int main(){
    //int n = 10;
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int s = 0;
    for (int i = 2; i <= n; i++)
    {
        if(isprime(i)){
            s += i;
        }
    }
    printf("Sum: %d\n", s);
    return 0;
}