#include <stdio.h>

int linear_search(int a[], int n, int x);//prototype
int binary_search(int a[], int n, int x);
int binary_search2(int a[], int n, int x);
int binary_search_recursion(int a[], int low, int high, int x);

int main(){
    //int a[]={9,1,5,7,10,12,18,20,17,11};
    int a[]={1,3,6,7,9,10,11,12,15,17,18};
    int n = sizeof(a)/sizeof(int);
    int x = 12;
    //int pos = linear_search(a,n,x);
    int pos = binary_search(a, 0, n-1, x);
    //int pos = binary_search_recursion(a, 0, n-1, x);
    if(pos==-1){
        printf("%d is not found in the array\n",x);
    }else{
        printf("Position of %d: %d\n", x, pos);
    }    
    return 0;
}

int linear_search(int a[], int n, int x){
    for (int i = 0; i < n; i++)
    {
        if(a[i]==x){
            return i;
        }
    }
    return -1;
}

int binary_search(int a[], int low, int high, int x){
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