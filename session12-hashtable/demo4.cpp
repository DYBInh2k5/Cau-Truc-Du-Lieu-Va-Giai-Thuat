#include "hashtable.h"

int main(){
    HashTable ht;
    for (int key = 0; key < 27; key++)
    {
        insert(&ht, key, key*10);
    }
    display(&ht);
    //lấy value của vài phần tử
    for (int key = 21; key < 31; key++)
    {
        printf("(%d,%d)\n", key, get(&ht, key));
    }
    //giải phóng bộ nhớ chứa các dslk
    remove(&ht);
    return 0;
}