#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA int

typedef struct NODE
{
    DATA info;
    NODE *next;
} NODE;

typedef struct
{
    NODE *head;
} LIST;

void initialize(LIST &list)
{
    list.head = NULL;
}

bool is_empty(LIST list)
{
    return list.head == NULL;
}

void traverse(LIST list)
{
    if(is_empty(list)){
        printf("The list is empty\n");
        return;
    }
    NODE *p = list.head;
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->next; // cho p trỏ đến node kế tiếp
    }
    printf("\n");
}

/**
 * @brief Tìm info trong list
 *
 * @param list
 * @param info
 * @return NODE*: địa chỉ của node tìm thấy
 */
NODE *search(LIST list, DATA info)
{
    NODE *p = list.head;
    while (p != NULL)
    {
        if (p->info == info)
        {
            return p;
        }
        p = p->next; // cho p trỏ đến node kế tiếp
    }
    return NULL;
}

/**
 * @brief Tìm info trong list
 *
 * @param list
 * @param info
 * @param q: chứa địa chỉ của node đứng trước node được tìm thấy (output parameter)
 * @return NODE*: địa chỉ của node tìm thấy
 */
NODE *search(LIST list, DATA info, NODE *&q)
{
    q = NULL;
    NODE *p = list.head;
    while (p != NULL)
    {
        if (p->info == info)
        {
            return p;
        }
        q = p;
        p = p->next; // cho p trỏ đến node kế tiếp
    }
    return NULL;
}

/**
 * @brief Tạo node mới chứa info
 *
 * @param info
 * @return NODE*: địa chỉ của node mới
 */
NODE *create_node(DATA info)
{
    NODE *p = new NODE; // cấp phát động bộ nhớ chứa một node
    if (p != NULL)
    { // nếu cấp phát bộ nhớ thành công
        p->info = info;
        p->next = NULL;
    }
    return p;
}

/**
 * @brief Thêm node mới chứa info ở đầu list
 *
 * @param list
 * @param info
 * @return NODE*: địa chỉ của node mới
 */
NODE *insert_head(LIST &list, DATA info)
{
    // tạo node mới
    NODE *p = create_node(info);
    // nếu tạo node mới thành công
    if (p != NULL)
    {
        // gắn node mới vào đầu list
        p->next = list.head;
        list.head = p;
    }
    return p;
}

/**
 * @brief Thêm node mới chứa info vào sau q
 *
 * @param info
 * @param q
 * @return NODE*: địa chỉ của node mới
 */
NODE *insert(LIST &list, DATA info, NODE *q)
{
    // tạo node mới
    NODE *p = create_node(info);
    // nếu tạo node mới thành công
    if (p != NULL)
    {
        if (q == NULL)
        {
            insert_head(list, info);
        }
        else
        {
            // gắn node mới vào sau q
            p->next = q->next;
            q->next = p;
        }
    }
    return p;
}

bool delete_head(LIST &list){
    //nếu list rỗng thì không có gì để xóa
    if(is_empty(list)){
        return false;
    }
    //nếu list khác rỗng
    NODE *p = list.head;
    list.head = p->next;
    delete p;//giải phóng vùng nhớ đang trỏ bởi p
    return true;
}

/**
 * @brief xóa node sau node q
 * 
 * @param list 
 * @param q 
 * @return true 
 * @return false 
 */
bool delete_after(LIST &list, NODE *q){
    /*
    1.Lưu đc node cần xóa vào p
    2.Chỉnh link của node q
    3.Giải phóng node p
    */
    if(q==NULL||q->next==NULL){
        return false;
    }
    NODE *p = q->next;
    q->next = p->next;
    delete p;
    return true;
}

bool delete_node(LIST &list, DATA x){
    /*
    1.Tìm x trong list để xác định p, q
    2.Xóa node sau q
    */
    NODE *p,*q;
    p = search(list, x, q);
    //nếu không tìm thấy x 
    if(p==NULL){
        return false;
    }
    //nếu node cần xóa là head
    if(p==list.head){
        return delete_head(list);
    }
    //nếu node cần xóa không là head
    return delete_after(list, q);
}

/**
 * @brief xóa tất cả các node trong list
 * 
 * @param list 
 */
void delete_all(LIST &list){
    while(delete_head(list));
}

/**
 * @brief tạo list chứa n số nguyên ngẫu nhiên thuộc [min, max]
 * 
 * @param list 
 * @param n 
 * @param min 
 * @param max 
 */
void random(LIST &list, int n, int min, int max){
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        insert_head(list, rand() % (max - min + 1) + min);
    }
}

int main()
{
    LIST list;
    initialize(list);
    /*
    insert_head(list, 10);
    insert_head(list, 20);
    insert_head(list, 90);
    insert_head(list, 30);
    insert_head(list, 50);
    traverse(list);
    */
    /*
    NODE *p=search(list, 90);
    if(p==NULL){
        printf("Not found\n");
    }else{
        printf("Found %d at address %u\n", p->info, p);
    }*/
    /*
    //insert 100 after 90
    NODE *p=search(list, 90);
    if(p==NULL){
        printf("Not found\n");
    }else{
        insert(100, p);
    }
    traverse(list);
    */
    /*
    // insert 100 before 90
    NODE *q;
    NODE *p = search(list, 90, q);
    if (p == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        insert(list, 100, q);
    }
    traverse(list);
    */
    /*
    //delete head
    delete_head(list);
    traverse(list);
    */
    /*
    //delete after: xóa node sau node 90
    NODE *p=search(list, 90);
    if(p==NULL){
        printf("Not found\n");
    }else{
        delete_after(list, p);
    }
    traverse(list);
    /*
    //xóa ở giữa list
    delete_node(list, 90);
    traverse(list);
    //xóa ở đầu list
    delete_node(list, 50);
    traverse(list);
    //xóa ở cuối list
    delete_node(list, 10);
    traverse(list);
    //trả lại bộ nhớ đã cấp phát động để lưu trữ list cho OS
    delete_all(list);
    traverse(list);
    */
    random(list, 10, 1, 100);
    traverse(list);
    return 0;
}
