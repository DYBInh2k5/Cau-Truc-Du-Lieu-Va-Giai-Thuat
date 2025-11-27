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

int bubble_sort(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            count++;
            if (a[j] < a[j - 1])
            {
                swap(a, j, j - 1);
            }
        }
    }
    return count;
}

int optimized_bubble_sort(int a[], int n)
{    
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int count_swapping = 0;
        for (int j = n - 1; j > i; j--)
        {
            count++;
            if (a[j] < a[j - 1])
            {
                swap(a, j, j - 1);
                count_swapping++;
            }
        }
        if(count_swapping==0) break;
    }
    return count;
}

int main()
{
    int a[] = {3, 1, 5, 8, 9, 10, 12};
    int b[] = {3, 1, 5, 8, 9, 10, 12};
    int n = sizeof(a) / sizeof(int);
    int count1 = bubble_sort(a, n);
    int count2 = optimized_bubble_sort(b, n);
    print(a, n);
    print(b, n);
    printf("count1 = %d, count2 = %d\n", count1, count2);
    return 0;
}