#include <stdio.h>
#include <string.h>

const int N =5;//số từ
const int M =10;//chiều dài tối đa của 1 từ

void swap(char a[][M], int i, int j)
{
    char temp[M];
    strcpy(temp, a[i]);
    strcpy(a[i], a[j]);
    strcpy(a[j], temp);
}

void interchange_sort(char a[][M], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(a[i], a[j])>0)
            {
                swap(a, i, j);
            }
        }
    }
}

int main()
{
    char a[N][M] = {"toi", "di", "hoc", "suot", "tuan"};
    interchange_sort(a, N);
    for (int i = 0; i < N; i++)
    {
        printf("%s\n", a[i]);
    }
    
    return 0;
}