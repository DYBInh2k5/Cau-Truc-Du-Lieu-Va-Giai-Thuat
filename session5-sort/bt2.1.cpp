#include <stdio.h>

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void optimized_bubble_sort(int a[], int n)
{    
    for (int i = 0; i < n - 1; i++)
    {
        int count = 0;
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a, j, j - 1);
                count++;
            }
        }
        if(count==0) break;
    }
}

int main()
{
    int a[] = {3, 1, 5, 8, 9, 10, 12};
    int n = sizeof(a) / sizeof(int);
    optimized_bubble_sort(a, n);
    print(a, n);
    return 0;
}