//dùng danh sách liên kết để hiện thực hàng đợi
#include <stdio.h>

#define DATA int

typedef struct NODE
{
    DATA info;
    NODE *next;
} NODE;

typedef struct
{
    NODE *head;
    NODE *tail;
    int count;
} QUEUE;

void initialize(QUEUE &q)
{
    q.head = q.tail = NULL
    q.count = 0;
}

bool is_empty(QUEUE q)
{
    return q.head == NULL;
    return q.tail == NULL;
    return q.count == 0;
}
bool is_full(QUEUE q){
    return false;
}
NODE *create_node(DATA info)
{
    NODE *p = new NODE; // cấp phát động bộ nhớ chứa một node
    if (p != NULL)
    { // nếu cấp phát bộ nhớ thành công
        p->info = info;
        p->next = NULL;
    }
    return p;
}
bool enqueue(QUEUE q, DATA value){
NODE* p = CreateNode(x);
    return false;
    if (p != NULL) {
        q.head->q.tail = p;
        q.count++;
    }else{
        q.tail->next = p;
        q.tail = p;
        q.count++;
        return true;
    }
    return false;
    
}
