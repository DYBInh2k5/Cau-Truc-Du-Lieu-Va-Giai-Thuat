//dùng danh sách đặc hiện thực hàng đợi
#include <stdio.h>

#define DATA int
#define N 100

typedef struct 
{
    int front;
    int rear;
    DATA a[N];
    int count;
}QUEUE;

void intialize(QUEUE &q){
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

bool is_empty(QUEUE q){
    return q.count == 0;
}

bool is_full(QUEUE q){
    return q.count == N;
}

bool enqueue(QUEUE q, DATA value){
if ( !IsFull(q) ) {
        q.rear = (q.rear + 1) % N;
        q.a[q.rear] = value;
        q.count++;
        return true;
    }
    return false;
}

bool dequeue(QUEUE &q, DATA &value) {
    
    if (is_empty(q)) { 
        value = q.a[q.front];  
        q.front = (q.front + 1) % N;  
        q.count--;
        return true;  
    }
    
    return false;  
}
get_front(QUEUE &q, DATA &value){
    if (IsEmpty(q)) {
    return false;
}

DATA x = q.a[q.front];
return true;
}
get_rear(QUEUE &q, DATA &value) {
    if ( !IsEmpty(q) ) {
        return false
        

    }DATA x = q.a[q.rear];
    return true;
}


