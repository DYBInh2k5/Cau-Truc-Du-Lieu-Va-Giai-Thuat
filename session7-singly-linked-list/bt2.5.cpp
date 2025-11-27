#include "doubly-linked-list.h"

void bubble_sort(DLIST &list){
    if(!is_empty(list)){
        DNODE *p = list.head;
        while(p != list.tail){
            DNODE *q = list.tail;
            while(q != p){
                if(q->info < q->prev->info){
                    DATA temp = q->info;
                    q->info = q->prev->info;
                    q->prev->info = temp;
                }
                q = q->prev;
            }
            p = p->next;
        }

    }
}

int main(){
    DLIST list;
    initialize(list);
    random(list, 0, 1, 100);
    traverse(list);
    bubble_sort(list);
    traverse(list);
    //giải phóng bộ nhớ đã cập nhật để lưu list
    delete_all(list);
    return 0;
}