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

int main()
{
    LIST list;
    initialize(list);
    random(list, 10, 1, 100);
    traverse(list);
    insert_last(list, 555);
    traverse(list);
    //giai phong bo nho
    delete_all(list);
    return 0;
}