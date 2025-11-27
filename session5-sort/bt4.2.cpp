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

int insertion_sort(int a[], int n)
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int pos = i;
        while(pos > 0 && a[pos - 1]>x){
            a[pos] = a[pos-1];
            pos--;
        }
        if(pos<i){
            a[pos] = x;
            count++;
        }        
    }
    return count;
}

int main()
{
    int a[] = {3, 1, 9, 5, 8, 12, 10};
    int n = sizeof(a) / sizeof(int);
    int count = insertion_sort(a, n);
    print(a, n);
    printf("Number of insertion: %d\n", count);
    return 0;
}