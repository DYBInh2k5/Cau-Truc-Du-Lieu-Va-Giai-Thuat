// 22301500-Võ Duy Bình 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA int

typedef struct DNODE
{
    DATA info;
    DNODE *next;
    DNODE *prev;
} DNODE;

typedef struct
{
    DNODE *head;
    DNODE *tail;
    int n;
} DLIST;

void initialize(DLIST &list)
{
    list.head = list.tail = NULL;
    list.n = 0;
}

bool is_empty(DLIST list)
{
    // return list.head == NULL;
    // return list.tail == NULL;
    return list.n == 0;
}

DNODE *create_node(DATA x)
{
    DNODE *p = new DNODE;
    if (p != NULL)
    {
        p->info = x;
        p->next = p->prev = NULL;
    }
    return p;
}

/**
 * @brief duyệt list theo chiều xuôi
 *
 * @param list
 */
void traverse(DLIST list)
{
    if (is_empty(list))
    {
        printf("The list is empty\n");
    }
    else
    {
        DNODE *p = list.head;
        while (p != NULL)
        {
            printf("%d ", p->info);
            p = p->next;
        }
        printf("\n");
    }
}

/**
 * @brief duyệt list theo chiều ngược
 *
 * @param list
 */
void reverse(DLIST list)
{
    if (is_empty(list))
    {
        printf("The list is empty\n");
    }
    else
    {
        DNODE *p = list.tail;
        while (p != NULL)
        {
            printf("%d ", p->info);
            p = p->prev;
        }
        printf("\n");
    }
}

/**
 * @brief thêm node mới chứa x vào đầu list
 *
 * @param list
 * @param x
 * @return DNODE*
 */
DNODE *insert_head(DLIST &list, DATA x)
{
    /*
    1.Tạo node mới chứa x
    2.Gắn node mới vào đầu list
    3.Tăng n lên 1
    */
    // 1
    DNODE *p = create_node(x);
    if (p != NULL)
    {
        // 2
        if (is_empty(list))
        {
            list.head = list.tail = p;
        }
        else
        {
            p->next = list.head;
            list.head->prev = p;
            list.head = p;
        }
        // 3
        list.n++;
    }
    return p;
}

/**
 * @brief thêm node mới chứa x vào cuối list
 *
 * @param list
 * @param x
 * @return DNODE*
 */
DNODE *insert_tail(DLIST &list, DATA x)
{
    /*
    1.Tạo node mới chứa x
    2.Gắn node mới vào cuối list
    3.Tăng n lên 1
    */
    // 1
    DNODE *p = create_node(x);
    if (p != NULL)
    {
        // 2
        if (is_empty(list))
        {
            list.head = list.tail = p;
        }
        else
        {
            list.tail->next = p;
            p->prev = list.tail;
            list.tail = p;
        }
        // 3
        list.n++;
    }
    return p;
}

/**
 * @brief thêm node mới chứa x vào sau node q (q != NULL)
 *
 * @param list
 * @param x
 * @param q
 * @return DNODE*
 */
DNODE *insert_after(DLIST &list, DATA x, DNODE *q)
{
    /*
    1.Tạo node mới chứa x
    2.Gắn node mới vào sau q
    3.Tăng n lên 1
    */
    // nếu q là node cuối cùng
    if (q == list.tail)
    {
        return insert_tail(list, x);
    }
    else
    {
        // 1
        DNODE *p = create_node(x);
        if (p != NULL)
        {
            // 2
            DNODE *t = q->next;
            p->next = t;
            q->next = p;
            t->prev = p;
            p->prev = q;
            // 3
            list.n++;
        }
        return p;
    }
}

/**
 * @brief tạo list ngẫu nhiên n phần tử thuộc [min, max]
 *
 * @param list
 * @param n
 * @param min
 * @param max
 */
void random(DLIST &list, int n, int min, int max)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        insert_head(list, rand() % (max - min + 1) + min);
    }
}

/**
 * @brief tìm x trong list
 * 
 * @param list 
 * @param x 
 * @return DNODE*: địa chỉ của node chứa x hoặc NULL 
 */
DNODE* search(DLIST list, DATA x){
    DNODE*p=list.head;
    while(p!=NULL)
    {
        if(p->info==x)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}

/**
 * @brief xóa node ở đầu list
 * 
 * @param list 
 * @return true 
 * @return false 
 */
bool delete_head(DLIST &list){
    if(!is_empty(list)){
        if(list.n == 1){
            delete list.head;
            list.head = list.tail = NULL;
        }else{
            DNODE* p = list.head;
            list.head = list.head->next;
            list.head->prev = NULL;
            delete p;
        }
        list.n--;
        return true;
    }
    return false;
}

/**
 * @brief xóa node ở cuối list
 * 
 * @param list 
 * @return true 
 * @return false 
 */
bool delete_tail(DLIST &list){
    if(!is_empty(list)){
        if(list.n == 1){
            delete list.head;
            list.head = list.tail = NULL;
        }else{
            DNODE* p = list.tail;
            list.tail = list.tail->prev;
            list.tail->next = NULL;
            delete p;
        }
        list.n--;
        return true;
    }
    return false;
}

/**
 * @brief xóa toàn bộ list
 * 
 * @param list 
 */
void delete_all(DLIST &list){
    while(delete_head(list));
}