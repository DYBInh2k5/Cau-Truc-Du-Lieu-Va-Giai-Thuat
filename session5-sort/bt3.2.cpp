#include <stdio.h>
#include <time.h>

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

void selection_sort(int a[], int n)
{
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
        }
    }
}

int main()
{
    int a[] = {3, 1, 9, 5, 8, 12, 10};
    int n = sizeof(a) / sizeof(int);
    clock_t start = clock();

    selection_sort(a, n);

    // int j=0;
    // for (int i = 0; i < 100000000; i++)
    // {
    //     j++;
    // }
    
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    print(a, n);
    printf("It is taken %lf seconds\n", time_taken);
    printf("It is taken %d ticks\n", end - start);
    return 0;
}