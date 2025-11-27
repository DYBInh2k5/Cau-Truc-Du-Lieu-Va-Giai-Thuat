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

int selection_sort(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(a, min, i);
            count++;
        }
    }
    return count;
}

int main()
{
    int a[] = {3, 1, 9, 5, 8, 12, 10};
    int n = sizeof(a) / sizeof(int);
    int count = selection_sort(a, n);
    print(a, n);
    printf("Number of swapping: %d\n", count);
    return 0;
}