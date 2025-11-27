#include "singly-linked-list.h"

/**
 * @brief thêm node mới chứa info vào cuối list
 *
 * @param list
 * @param info
 * @return NODE*: địa chỉ của node mới
 */
NODE *insert_last(LIST &list, DATA info)
{
    //1. Xác định node cuối cùng (cho q trỏ vào node cuối cùng)
    NODE *q = list.head;
    // di chuyển q đến node cuối cùng
    while (q != NULL && q->next != NULL)
    {
        q = q->next;
    }
    //2. Gắn node mới vào sau node cuối cùng (gắn vào sau q)
    return insert(list, info, q);
}

void split(LIST &list, LIST &list1, LIST &list2){
    initialize(list1);
    initialize(list2);

    NODE* p = list.head;
    while(p != NULL){
        if(p->info % 2 == 0){
            insert_last(list1, p->info);
        }else{
            insert_last(list2, p->info);
        }
        p = p->next;
    }
}

int main(){
    LIST list, list1, list2;
    initialize(list);
    random(list, 10, 1, 100);
    traverse(list);
    split(list, list1, list2);
    traverse(list1);
    traverse(list2);
    //giai phong bo nho
    delete_all(list);
    delete_all(list1);
    delete_all(list2);
    return 0;
}