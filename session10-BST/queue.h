//dùng danh sách đặc để hiện thực hàng đợi
#include <stdio.h>
#include "types.h"

void initialize(QUEUE &q){
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

bool is_empty_queue(QUEUE q){
    return q.count == 0;
}

bool is_full_queue(QUEUE q){
    return q.count == N;
}

bool enqueue(QUEUE &q, QDATA value){
    if(!is_full_queue(q)){
        q.rear = (q.rear + 1) % N;
        q.a[q.rear] = value;
        q.count++;
        return true;
    }
    return false;
}

bool dequeue(QUEUE &q, QDATA &value){
    if(!is_empty_queue(q)){
        value = q.a[q.front];
        q.front = (q.front + 1) % N;
        q.count--;
        return true;
    }
    return false;
}

bool get_front(QUEUE q, QDATA &value){
    if(!is_empty_queue(q)){
        value = q.a[q.front];
        return true;
    }
    return false;
}

bool get_rear(QUEUE q, QDATA &value){
    if(!is_empty_queue(q)){
        value = q.a[q.rear];
        return true;
    }
    return false;
}