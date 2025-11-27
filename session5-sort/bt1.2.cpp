#include <stdio.h>

void print(char a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", a[i]);
    }
    printf("\n");
}

void swap(char a[], int i, int j)
{
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void interchange_sort(char a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a, i, j);
            }
        }
    }
}

int main()
{
    char a[] = "toidihoc";
    int n = sizeof(a) / sizeof(char)-1;
    interchange_sort(a, n);
    print(a, n);
    return 0;
}