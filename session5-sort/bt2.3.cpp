#include <stdio.h>
#include <stdlib.h>
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

double bubble_sort(int a[], int n)
{
    clock_t start = clock();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a, j, j - 1);
            }
        }
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    return time_taken;
}

double optimized_bubble_sort(int a[], int n)
{    
    clock_t start = clock();
    for (int i = 0; i < n - 1; i++)
    {
        int count_swapping = 0;
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a, j, j - 1);
                count_swapping++;
            }
        }
        if(count_swapping==0) break;
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    return time_taken;
}

void generate_random_array(int a[], int n, int min, int max)
{
    // Khởi tạo seed cho hàm rand()
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % (max - min + 1) + min;
    }
}

void copy_array(int d[], int s[], int n){
    for (int i = 0; i < n; i++)
    {
        d[i] = s[i];
    }
}

int main()
{
    int n = 10000;    // Số lượng phần tử
    int min = 1;   // Giá trị nhỏ nhất
    int max = 100000; // Giá trị lớn nhất
    int a[n], b[n];// Khai báo arrays

    generate_random_array(a, n, min, max);
    copy_array(b, a, n);

    double time_taken1 = bubble_sort(a, n);
    double time_taken2 = optimized_bubble_sort(b, n);
    print(a, n);
    print(b, n);
    printf("time_taken1 = %lf, time_taken2 = %lf\n", time_taken1, time_taken2);
    return 0;
}