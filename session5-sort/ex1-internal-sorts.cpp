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

void interchange_sort(int a[], int n)
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

void bubble_sort(int a[], int n)
{
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

void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int pos = i;
        while (pos > 0 && a[pos - 1] > x)
        {
            a[pos] = a[pos - 1];
            pos--;
        }
        a[pos] = x;
    }
}

// Tìm vị trí chèn x
int binary_search(int arr[], int x, int low, int high) {
    int result = -1; // Nếu không tìm thấy phần tử nào hợp lệ

    while (low <= high) {
        int mid = (low + high) / 2;

        // Nếu phần tử ở giữa nhỏ hơn hoặc bằng x, lưu lại vị trí và tìm tiếp ở bên phải
        if (arr[mid] <= x) {
            result = mid;
            low = mid + 1;  // Tìm tiếp ở nửa phải (phần lớn hơn)
        }
        // Nếu phần tử ở giữa lớn hơn x, tìm tiếp ở nửa trái
        else {
            high = mid - 1;
        }
    }

    return result+1; // Trả về vị trí nếu tìm thấy, nếu không thì trả về -1
}

void insertion_binary_sort(int a[], int n)
{
    int i, pos, j, k, x;
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        x = a[i];
        // tìm vị trí để chèn x vào
        pos = binary_search(a, x, 0, j);
        // di chuyển các phần tử sau pos sang phải
        while (j >= pos)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

int partition(int arr[], int left, int right){
    int pivot = arr[right];
    int i = left;
    int j = right - 1;
    while (i<=j){
        while(arr[i]<=pivot && i<right) i++;
        while (arr[j]>pivot && j>=0) j--;
        if(i<j) swap(arr, i, j);    
    }
    swap(arr, i, right);
    return i;   
}

void quick_sort(int arr[], int left, int right){
    if (left < right){
        int pi = partition(arr, left, right);
        quick_sort(arr, left, pi - 1);
        quick_sort(arr, pi + 1, right);
    }
}


int main()
{
    int a[] = {3, 1, 9, 5, 5, 8, 12, 10};
    int n = sizeof(a) / sizeof(int);
    // interchange_sort(a, n);
    // bubble_sort(a, n);
    // selection_sort(a, n);
    //insertion_sort(a, n);
    //insertion_binary_sort(a, n);
    quick_sort(a, 0, n-1);
    print(a, n);
    return 0;
}