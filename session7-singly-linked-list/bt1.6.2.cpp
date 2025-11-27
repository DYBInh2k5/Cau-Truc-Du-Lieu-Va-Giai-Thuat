#include "singly-linked-list.h"

void split(LIST &list, LIST &list1, LIST &list2){
    initialize(list1);
    initialize(list2);

    NODE *p = list.head;
    NODE *p1 = NULL, *p2 = NULL;
    while(p != NULL){
        if(p->info % 2 == 0){
            p1 = insert(list1, p->info, p1);
        }else{
            p2 = insert(list2, p->info, p2);
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