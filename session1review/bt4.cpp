#include <stdio.h>
const int N = 5;

void input(int a[]){
    for (int i = 0; i < N; i++)
    {
        printf("a[%d]=",i);
        scanf("%d", &a[i]);
    }  
}

void output(int a[]){
    for (int i = 0; i < N; i++)
    {
        printf("a[%d]=%d\n", i, a[i]);
    }  
}

int sum(int a[]){

}

int product(int a[]){
    
}

double average(int a[]){

}

int max(int a[]){

}

int main(){
    int a[N];
    input(a);
    output(a);
}