#include "doubly-linked-list.h"

int main(){
    DLIST list;
    initialize(list);
    random(list, 10, 1, 100);
    traverse(list);
    reverse(list);
    //giải phóng bộ nhớ đã cấp phát động để lưu list
    delete_all(list);
    traverse(list);
    return 0;
}