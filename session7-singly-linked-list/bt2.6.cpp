#include "doubly-linked-list.h"



DNODE* insert(DLIST &list, int x){
    DNODE *p = list.head;
    while(p != NULL && p->info <=x){
        if(p->info <= x){
            p = p->next;
        }else{
            return p->prev;
        }
    }
    return list.tail;
}
DNODE* insert(DLIST &list, int x){
    /*
    1.tìm node có info lớn nhất <= x
    2.Nếu tìm thấy:
        - insert node chứa x vào sau node tìm được
    3.Nếu không tìm thấy:
        - insert node chứa x vào đầu danh sách list

    */
    DNODE *p = find_largest(list, x);
    if(p != NULL){
        return insert_after(list, x, p);

    }else{
        return insert_head(list, x);
    }


}


int main(){
    DLIST list;
    initialize(list);
    insert_head(list, 100);
    insert_head(list, 80);
    insert_head(list, 60);
    insert_head(list, 40);
    insert_head(list, 20);

    traverse(list);
    insert(list, 50)
    traverse(list);
    //giải phóng bộ nhớ đã cập nhật để lưu list
    delete_all(list);
    return 0;
}