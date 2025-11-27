#include "Queue.h"

int main(){
    QUEUE q;
    intialize(q);
    //thêm các phần tử hàng đợi vào q
    enqueue(q,10);
    enqueue(q,8);
    enqueue(q,9);
    enqueue(q,4);
    enqueue(q,1);
    //lấy các phần tử q
    DATA value;
    while(dequeue(q, value)){
        printf("%d\n",value);
    }
    return 0;

}