//dùng danh sách liên kết đơn tạo stack
#include <stdio.h>

#define DATA double

typedef struct NODE
{
    DATA info;
    NODE *next;
} NODE;

typedef struct
{
    NODE *head;
} STACK;

void initialize(STACK &s)
{
    s.head = NULL;
}

bool is_empty(STACK s)
{
    return s.head == NULL;
}

bool is_full(STACK s){
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

NODE *insert_head(STACK &s, DATA info)
{
    // tạo node mới
    NODE *p = create_node(info);
    // nếu tạo node mới thành công
    if (p != NULL)
    {
        // gắn node mới vào đầu s
        p->next = s.head;
        s.head = p;
    }
    return p;
}

bool push(STACK &s, DATA value){
    NODE *p = insert_head(s, value);
    return p != NULL;
}

bool delete_head(STACK &s)
{
    // nếu list rỗng thì không có gì để xóa
    if (is_empty(s))
    {
        return false;
    }
    // nếu list khác rỗng
    NODE *p = s.head;
    s.head = p->next;
    delete p; // giải phóng vùng nhớ đang trỏ bởi p
    return true;
}

bool pop(STACK &s, DATA &value){
    if(!is_empty(s)){
        value = s.head->info;
        delete_head(s);
        return true;
    }
    return false;
}

bool peek(STACK &s, DATA &value){
    if(!is_empty(s)){
        value = s.head->info;
        return true;
    }
    return false;
}