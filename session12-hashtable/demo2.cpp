#include "hashtable.h"

int main(){
    HashTable ht;
    for (int key = 0; key < 27; key++)
    {
        insert(&ht, key, key*10);
    }
    display(&ht);
    //tìm kiếm phần tử có key=10
    int key = 10;
    Node *p = search(&ht, key);
    if(p != NULL){
        printf("Found (%d,%d) at address %u\n", p->key, p->value, p);
    }else{
        printf("Not found!\n");
    }
    //giải phóng bộ nhớ chứa các dslk
    remove(&ht);
    return 0;
}