#include "doubly-linked-list.h"

/**
 * @brief kiểm tra tính đối xứng của list
 * 
 * @param list
 * @return true
 * @return false
 */


bool is_symmetry(DLIST list){
    
    
    DNODE *p = list.head;
    DNODE *q = list.tail;
    while(p !=NULL && q != NULL && p != q && p->next !=q){
        if(p->info == q->info){
            p = p->next;
            q = q->prev;
        }else{
            return false;
        }
    }
    return true;
    
}

int main(){
    DLIST list;
    initialize(list);
    insert_head(list,1);
    insert_head(list,2);
    insert_head(list,3);
    insert_head(list,2);
    insert_head(list,1);

    traverse(list);
    bool symmetry = is_symmetry(list);
    if(symmetry){
        printf("the list is symmetry.\n");
    }else{
        printf("the list is not symmetry.\n")
    }
    //giải phóng bộ nhớ đã cập nhật để lưu list
    delete_all(list);
    return 0;
}