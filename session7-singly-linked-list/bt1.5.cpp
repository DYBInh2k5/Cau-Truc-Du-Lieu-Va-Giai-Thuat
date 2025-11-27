#include "singly-linked-list.h"

/**
 * @brief tìm node chứa info lớn nhất mà <= x
 * 
 * @param list 
 * @param x 
 * @return NODE*: địa của node tìm được/NULL 
 */
NODE* search_largest(LIST list, int x){
    NODE* p = NULL;
    NODE* q = list.head;
    while(q != NULL && q->info < x){
        p = q;
        q = q->next;
    }
    return p;
}

/**
 * @brief chèn x vào list số nguyên tăng dần
 * 
 * @param list 
 * @param x 
 */
void insert(LIST &list, int x){
    /*
    1. Tìm node q có info lớn nhất mà <= x
    2. Chèn node chứa x vào sau q
    */
    NODE* q = search_largest(list, x);
    insert(list, x, q);
}

int main(){
    LIST list;
    initialize(list);
    insert_head(list, 10);
    insert_head(list, 8);
    insert_head(list, 5);
    insert_head(list, 4);
    insert_head(list, 1);
    traverse(list);
    insert(list, 8);
    traverse(list);
    //giai phong bo nho
    delete_all(list);
    return 0;
}