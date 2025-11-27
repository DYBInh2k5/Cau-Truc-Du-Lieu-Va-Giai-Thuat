#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA Student

struct Student{
    int id;//field, attribute
    char name[50];
    int age; 
};

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
        printf("Id  : %d\n", p->info.id);
        printf("Name: %s\n", p->info.name);
        printf("Age : %d\n", p->info.age);
        printf("\n");
        p = p->next; // cho p trỏ đến node kế tiếp
    }
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
 * @brief xóa tất cả các node trong list
 * 
 * @param list 
 */
void delete_all(LIST &list){
    while(delete_head(list));
}

/*
int main(){
    LIST list;
    initialize(list);
    insert_head(list, {1, "Tran Thanh Hai", 20});
    insert_head(list, {2, "Tran Thanh Tung", 21});
    insert_head(list, {3, "Tran Thanh Minh", 22});
    insert_head(list, {4, "Tran Thanh Chinh", 18});
    insert_head(list, {5, "Tran Thanh Chien", 19});
    traverse(list);
    //giai phong bo nho
    delete_all(list);
    return 0;
}
*/

int main(){
    LIST list;
    initialize(list);
    NODE *p =list.head;
    p = insert(list, {1, "Tran Thanh Hai", 20}, p);
    p = insert(list, {2, "Tran Thanh Tung", 21}, p);
    p = insert(list, {3, "Tran Thanh Minh", 22}, p);
    p = insert(list, {4, "Tran Thanh Chinh", 18}, p);
    p = insert(list, {5, "Tran Thanh Chien", 19}, p);
    traverse(list);
    //giai phong bo nho
    delete_all(list);
    return 0;
}