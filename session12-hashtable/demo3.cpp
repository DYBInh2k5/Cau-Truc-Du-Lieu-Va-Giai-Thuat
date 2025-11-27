#include "hashtable.h"

int main(){
    HashTable ht;
    for (int key = 0; key < 27; key++)
    {
        insert(&ht, key, key*10);
    }
    display(&ht);
    //xóa vài phần tử
    remove(&ht, 10);
    remove(&ht, 12);
    //in lại ht sau khi xóa
    printf("\nAfter removing some elements:\n");
    display(&ht);
    //giải phóng bộ nhớ chứa các dslk
    remove(&ht);
    return 0;
}