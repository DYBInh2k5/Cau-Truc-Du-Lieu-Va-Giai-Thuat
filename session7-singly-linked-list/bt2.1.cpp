#include "doubly-linked-list.h"

/**
 * @brief Thêm node mới có giá trị x vào trước node q (q != NULL)
 * 
 * @param list 
 * @param x 
 * @param q 
 * @return DNODE*: địa chỉ của node mới
 */
DNODE* insert_before(DLIST &list, DATA x, DNODE* q){
    if(q==list.head){
        return insert_head(list, x);
    }else{
        DNODE* p = create_node(x);
        if(p != NULL){
            DNODE* t = q->prev;
            p->next = q;
            t->next = p;
            q->prev = p;
            p->prev = t;
            list.n++;
        }
        return p;
    }
}

/**
 * @brief 2.1. Thêm node mới có giá trị x vào trước node 
 * có giá trị y trong danh sách số nguyên
 * 
 * @param list 
 * @param x 
 * @param y 
 * @return DNODE*: địa chỉ của node mới
 */
DNODE* insert_before(DLIST &list, DATA x, DATA y){
    /*
    1. Tìm node chứa y (q trỏ vào node chứa y)
    2. Chèn node mới chứa x trước q
    */
    //1. Tìm node chứa y (q trỏ vào node chứa y)
    DNODE* q = search(list, y);
    if(q != NULL){
        //2. Chèn node mới chứa x trước q
        return insert_before(list, x, q);
    }
    return NULL;
}

int main(){
    DLIST list;
    initialize(list);
    insert_head(list, 10);
    insert_head(list, 100);
    insert_head(list, 80);
    insert_head(list, 30);
    insert_head(list, 20);
    traverse(list);
    insert_before(list, 200, 100);
    traverse(list);
    //giải phóng bộ nhớ đã cấp phát động để lưu list
    delete_all(list);
    traverse(list);
    return 0;
}