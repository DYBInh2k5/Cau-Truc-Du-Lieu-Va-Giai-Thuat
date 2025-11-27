#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"

typedef struct NODE
{
    STUDENT student;
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

bool is_empty_list(LIST list)
{
    return list.head == NULL;
}

void traverse(LIST list)
{
    if (is_empty_list(list))
    {
        printf("The list is empty\n");
        return;
    }
    NODE *p = list.head;
    while (p != NULL)
    {
        printf("| %6d | %-50s | %6.2lf |\n", p->student.id, p->student.name, p->student.score);
        p = p->next; // cho p trỏ đến node kế tiếp
    }
}

void traverse2(LIST list, char *s)
{
    if (is_empty_list(list))
    {
        printf("The list is empty\n");
        return;
    }
    strcpy(s,"");
    NODE *p = list.head;
    while (p != NULL && p->next != NULL)
    {
        sprintf(s, "%s%d-->", s, p->student.id);        
        p = p->next; // cho p trỏ đến node kế tiếp
    }
    sprintf(s, "%s%d", s, p->student.id);
}

/**
 * @brief Tìm student trong list
 *
 * @param list
 * @param student
 * @return NODE*: địa chỉ của node tìm thấy
 */
NODE *search(LIST list, int id)
{
    NODE *p = list.head;
    while (p != NULL)
    {
        if (p->student.id == id)
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
NODE *search(LIST list, int id, NODE *&q)
{
    q = NULL;
    NODE *p = list.head;
    while (p != NULL)
    {
        if (p->student.id == id)
        {
            return p;
        }
        q = p;
        p = p->next; // cho p trỏ đến node kế tiếp
    }
    return NULL;
}

/**
 * @brief Tạo node mới chứa student
 *
 * @param student
 * @return NODE*: địa chỉ của node mới
 */
NODE *list_create_node(STUDENT student)
{
    NODE *p = new NODE; // cấp phát động bộ nhớ chứa một node
    if (p != NULL)
    { // nếu cấp phát bộ nhớ thành công
        p->student = student;
        p->next = NULL;
    }
    return p;
}

/**
 * @brief Thêm node mới chứa student ở đầu list
 *
 * @param list
 * @param student
 * @return NODE*: địa chỉ của node mới
 */
NODE *insert_head(LIST &list, STUDENT student)
{
    // tạo node mới
    NODE *p = list_create_node(student);
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
 * @brief Thêm node mới chứa student vào sau q
 *
 * @param student
 * @param q
 * @return NODE*: địa chỉ của node mới
 */
NODE *insert(LIST &list, STUDENT student, NODE *q)
{
    if (q == NULL)
    {
        return insert_head(list, student);
    }
    else
    {
        // tạo node mới
        NODE *p = list_create_node(student);
        // nếu tạo node mới thành công
        if (p != NULL)
        {
            // gắn node mới vào sau q
            p->next = q->next;
            q->next = p;
        }
        return p;
    }
}

bool delete_head(LIST &list)
{
    // nếu list rỗng thì không có gì để xóa
    if (is_empty_list(list))
    {
        return false;
    }
    // nếu list khác rỗng
    NODE *p = list.head;
    list.head = p->next;
    delete p; // giải phóng vùng nhớ đang trỏ bởi p
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
bool delete_after(LIST &list, NODE *q)
{
    /*
    1.Lưu đc node cần xóa vào p
    2.Chỉnh link của node q
    3.Giải phóng node p
    */
    if (q == NULL || q->next == NULL)
    {
        return false;
    }
    NODE *p = q->next;
    q->next = p->next;
    delete p;
    return true;
}

bool delete_node(LIST &list, int id)
{
    /*
    1.Tìm id trong list để xác định p, q
    2.Xóa node sau q
    */
    NODE *p, *q;
    p = search(list, id, q);
    // nếu không tìm thấy id
    if (p == NULL)
    {
        return false;
    }
    // nếu node cần xóa là head
    if (p == list.head)
    {
        return delete_head(list);
    }
    // nếu node cần xóa không là head
    return delete_after(list, q);
}

/**
 * @brief xóa tất cả các node trong list
 *
 * @param list
 */
void delete_all(LIST &list)
{
    while (delete_head(list))
        ;
}