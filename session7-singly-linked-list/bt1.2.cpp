
#include "singly-linked-list.h"

/**
 * @brief nối list2 vào list1
 * 
 */
void join(LIST &list1, LIST list2){
    //1. Xác định node cuối cùng của list1 (q)
    NODE *q = list1.head;
    // di chuyển q đến node cuối cùng
    while (q != NULL && q->next != NULL)
    {
        q = q->next;
    }
    //2. Cho q->next trỏ vào list2
    if(q != NULL){
        q->next = list2.head;
    }else{//q==NULL nếu list1 rỗng
        list1.head = list2.head;
    } 
}

int main()
{
    LIST list1, list2;
    initialize(list1);
    initialize(list2);
    random(list1, 4, 1, 100);
    random(list2, 6, 1, 100);
    traverse(list1);
    traverse(list2);

    join(list1, list2);
    traverse(list1);
    traverse(list2);

    //giai phong bo nho
    delete_all(list1);
    delete_all(list2);
    return 0;
}
1