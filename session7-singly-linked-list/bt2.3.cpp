#include "doubly-linked-list.h"


/**
 * @brief xoay list sang phải n lần
 * 
 * @param list
 * @param n (n>=0)
 */
void rotate(DLIST &list, int n){
    if(!is_empty(list)){
    DNODE *p = list.head;
    for (int i = 0; i < n; i++)
    {
        /*
        1.cho p trỏ vào node kế tiếp
        2.thêm head->info vào cuối list
        3.delete head
        4.cho head = p
         */
        p=p->next;
        insert_tail(list, list.head->info);
        delete_head(list);
        if(list.n == 1){
            p = list.tail;
        }
        list.head = p;
    }
}


}
int main(){
    DLIST list;
    initialize(list);
    random(list, 2, 1, 100);
    traverse(list);
    rotate(list,2);
    traverse(list);
    //giải phóng bộ nhớ đã cập nhật để lưu list
    delete_all(list);
    return 0;
}