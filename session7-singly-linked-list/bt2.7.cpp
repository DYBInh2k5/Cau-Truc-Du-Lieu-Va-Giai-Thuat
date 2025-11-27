#include "doubly-linked-list.h"

void join(DLIST list1, DLIST list2, DLIST &list){
    initialize(list);
    DNODE *p = list1.head;
    DNODE *q = list2.head;
    while(p != NULL && q != NULL){
        if(p->info <= q->info){
            insert_tail(list, p->info);
            p = p->next;
        }else{
            insert_tail(list, q->info);
            q = q->next;
        }
    }
    while(p !=NULL){
        insert_tail(list, p->info);
        p = p->next;
    }
    while(q != NULL){

    }
}
int main(){
    DLIST list1, list2,list;
    initialize(list1);
    initialize(list2);
    insert_head(list1, 100);
    insert_head(list1, 80);
    insert_head(list1, 60);
    insert_head(list1, 40);
    insert_head(list1, 20);

    insert_head(list2, 120);
    insert_head(list2, 110);
    insert_head(list2, 50);
    insert_head(list2, 30);
    insert_head(list2, 25);

    traverse(list1);
    traverse(list2);

    join(list1, list2, list);
   
    traverse(list);
    //giải phóng bộ nhớ đã cập nhật để lưu list
    delete_all(list);
    return 0;
}