#include <stdio.h>

#define MAX 100 //số lượng phần tử tối đa
//const int MAX = 100;

typedef struct {
    int n; //số lượng phần tử thực sự
    int a[MAX]; //dãy các phần tử kiểu int
} CLIST;

void initialize(CLIST &list) {
    list.n = 0;
}

bool is_empty(CLIST list){
    // if(list.n == 0) return true;
    // return false;
    return list.n == 0;
}

bool is_full(CLIST list){
    return list.n == MAX;
}

bool insert(CLIST &list, int k, int newinfo) {
    //nếu danh sach chưa đầy và k hợp lệ
    if ( !is_full(list) && (0 <= k && k <= list.n) ) {
        //di chuyển các phần tử từ vị trí k ra phía sau
        for (int i = list.n; i > k; i--) {
            list.a[i] = list.a[i-1];
        }
        list.a[k] = newinfo;
        //tăng số phần tử lên 1 sau khi thêm
        list.n++;
        return true;
    }
    return false;
}

bool remove(CLIST &list, int k){
    //nếu k hợp lệ
    if(0<=k && k<list.n){
        //di chuyển các phần tử từ vị trí k + 1 sang trái
        for (int i = k; i < list.n-1; i++)
        {
            list.a[i] = list.a[i+1];
        }
        //giảm số phần tử đi 1 sau khi xóa
        list.n--;
        return true;        
    }
    return false;
}

