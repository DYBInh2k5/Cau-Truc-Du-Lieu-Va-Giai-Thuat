
#include <stdio.h>
const int R=3;
const int C=3;

void input(int a[][C]){
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }        
    }    
}

void output(int a[][C]){
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            //printf("a[%d][%d]=%d ", i, j, a[i][j]);
            printf("%d ", a[i][j]);
        } 
        printf("\n");
    }    
}

int sum(int a[][C]){
    int s = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            s += a[i][j];
        } 
    } 
    return s;   
}

int sum_main_diagonal(int a[][C]){
    int s = 0;
    for (int i = 0; i < R; i++)
    {
        s += a[i][i];
    } 
    return s;   
}

int sum_secondary_diagonal(int a[][C]){
    int s = 0;
    for (int i = 0; i < R; i++)
    {
        s += a[i][C-1-i];
    } 
    return s;   
}

int main(){
    /*int a[R][C];
    input(a);*/
    int a[R][C]={
        {1, 3, 8},
        {6, 9, 7},
        {2, 5, 9}
    };
    output(a);
    printf("Sum: %d\n", sum(a));
    printf("Sum of the main diagonal: %d\n", sum_main_diagonal(a));
    printf("Sum of the secondary diagonal: %d\n", sum_secondary_diagonal(a));
    return 0;
}
1