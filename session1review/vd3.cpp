
#include <stdio.h>
#include <stdlib.h>

int sum(int n){
    int s=0;
    for (int i = 1; i <= n; i++)
    {
        s+=i;
    }
    return s;
}

int factorial(int n){//n>0
    int p=1;
    for (int i = 1; i <= n; i++)
    {
        p*=i;
    }
    return p;
}

int main(){		
    double s = 0;
    int n = 2;
    for (int i = 1; i <= n; i++)
    {
        s += (double)sum(i)/factorial(i);
    }
    printf("Sum: %.2lf\n", s);
}
1