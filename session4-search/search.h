#include <stdio.h>

int linear_search(int a[], int n, int x){
    for (int i = 0; i < n; i++)
    {
        if(a[i]==x){
            return i;
        }
    }
    return -1;
}

int binary_search(int a[], int n, int x){
    int low = 0;
    int high= n - 1;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid]==x){//tim thay
            return mid;
        }else if(a[mid]<x){//tim tiep o nua phai
            low = mid + 1;
        }else{//tim tiep o nua trai
            high = mid - 1;
        }
    }
    return -1;
}

int binary_search2(int a[], int n, int x){
    int low = 0;
    int high= n - 1;
    int count = 0;
    while(low <= high){
        int mid = (low+high)/2;
        count++;
        if(a[mid]==x){//tim thay
            printf("Count: %d\n", count);
            return mid;
        }else if(a[mid]<x){//tim tiep o nua phai
            low = mid + 1;
        }else{//tim tiep o nua trai
            high = mid - 1;
        }
    }
    printf("Count: %d\n", count);
    return -1;
}

int binary_search_recursion(int a[], int low, int high, int x){
    if(low <= high){
        int mid = (low+high)/2;
        if(a[mid]==x){
            return mid;
        }else if(a[mid]<x){//tim o nua phai
            return binary_search_recursion(a,mid+1,high,x);
        }else{//tim o nua trai
            return binary_search_recursion(a,low,mid-1,x);
        }
    }
    return -1;
}