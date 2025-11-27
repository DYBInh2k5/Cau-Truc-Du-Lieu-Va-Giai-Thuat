#include "singly-linked-list.h"

//dùng interchange sort
void sort(LIST &list){    
    NODE *p,*q;
    p = list.head;
    while(p != NULL && p->next != NULL){
        q = p->next;
        while(q != NULL){
            if(p->info > q->info){
                //swap info của 2 node p và q
                DATA temp = p->info;
                p->info = q->info;
                q->info = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

int main(){
    LIST list;
    initialize(list);
    random(list, 10, 1, 100);
    traverse(list);
    sort(list);
    traverse(list);
    //giai phong bo nho
    delete_all(list);
    return 0;
}