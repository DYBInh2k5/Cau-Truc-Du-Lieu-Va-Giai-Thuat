#include "singly-linked-list.h"

void reverse1(LIST &list){
    //1. Tạo ds mới lst
    LIST lst;
    initialize(lst);
    //2. Lấy từng phần tử của list insert_head(lst) 
    NODE* p = list.head;
    while(p != NULL){
        insert_head(lst, p->info);     
        p=p->next;   
    }
    //3. Xóa list
    delete_all(list);
    //4. Cập nhật list.head
    list.head = lst.head;
}

void reverse2(LIST &list){
    /*
    1. Nếu là node đầu tiên của list --> biến thành node cuối cùng
    2. Từ node thứ 2 trở đi: cho next trỏ vào node đứng trước
    */
    //nếu list khác rỗng mới thực hiện đão ngược    
    if(!is_empty(list)){
        //1. Khởi tạo p, q
        NODE* p = list.head;
        NODE* q = p->next;
        //2. Làm p trở thành node cuối cùng
        p->next = NULL;
        //3. Duyệt qua list, lấy từng node để chỉnh link
        while(q != NULL){
            NODE* t = p;
            p = q;
            q = q->next;//di chuyển q sang node kế tiếp
            p->next = t;//chỉnh link của node
        }
        //3. Cập nhật head
        list.head = p;
    }
}

int main(){
    LIST list;
    initialize(list);
    random(list, 10, 1, 100);
    traverse(list);
    reverse1(list);
    traverse(list);
    reverse2(list);
    traverse(list);
    //giai phong bo nho
    delete_all(list);
    return 0;
}