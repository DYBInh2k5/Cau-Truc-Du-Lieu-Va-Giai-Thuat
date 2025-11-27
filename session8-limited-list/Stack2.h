//dùng danh sách liên kết tạo stack
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
} STACK;

void initialize(STACK &s)
{
    STACK.head = NULL;
}
bool is_empty(STACK s)
{
    return Stack.head == NULL;
}
bool is_full(STACK s)
{
    return false;
}
/**
 * @brief Tạo node mới chứa info
 *
 * @param info
 * @return NODE*: địa chỉ của node mới
 */
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
/**
 * @brief Thêm node mới chứa info ở đầu STACK
 *
 * @param STACK
 * @param info
 * @return NODE*: địa chỉ của node mới
 */
NODE *insert_head(STACK &STACK, DATA info)
{
    // tạo node mới
    NODE *p = create_node(info);
    // nếu tạo node mới thành công
    if (p != NULL)
    {
        // gắn node mới vào đầu STACK
        p->next = STACK.head;
        STACK.head = p;
    }
    return p;
}
bool push(STACK &s,DATA value){
    /*
    if (STACK_full(s){
        //s.top++;
        //s.a[s.top]=value;
        NODE* p = insert_head(s, value);
        return p != NULL;

    }
        
    return false;
    */
   NODE* p = insert_head(s, value);
   return p != NULL;
}
bool pop(STACK &s , DATA &value)
{
    // nếu STACK rỗng thì không có gì để xóa
    if (is_empty(STACK))
    {
        return false;
    }
    // nếu STACK khác rỗng
    NODE *p = STACK.head;
    s.head = p->next;
    value = p->info;
    delete p; // giải phóng vùng nhớ đang trỏ bởi p
    return true;
}
bool peek(STACK &s, DATA &value){
    if (!is_empty(s)) { // Kiểm tra xem stack không rỗng
        value = s.head->info; // Lấy giá trị từ node đỉnh
        return true; // Thành công
}
    return false; // Stack rỗng, không thể lấy giá trị
}