#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA Student

struct Student
{
    int id; // field, attribute
    char name[50];
    int age;
};

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
            printf("Id: %d\n", p->info.id);
            printf("Name: %s\n", p->info.name);
            printf("Age: %d\n", p->info.age);
            p = p->next;
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
 * @brief thêm node mới chứa x vào sau node q
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
    if (q == NULL)
    {
        return insert_head(list, x);
    }
    else
    {
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
}

/**
 * @brief xóa node ở đầu list
 *
 * @param list
 * @return true
 * @return false
 */
bool delete_head(DLIST &list)
{
    if (!is_empty(list))
    {
        if (list.n == 1)
        {
            delete list.head;
            list.head = list.tail = NULL;
        }
        else
        {
            DNODE *p = list.head;
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
bool delete_tail(DLIST &list)
{
    if (!is_empty(list))
    {
        if (list.n == 1)
        {
            delete list.head;
            list.head = list.tail = NULL;
        }
        else
        {
            DNODE *p = list.tail;
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
void delete_all(DLIST &list)
{
    while (delete_head(list))
        ;
}

DNODE *find_largest_age(DLIST &list, DATA x)
{
    DNODE *p = list.head;
    while (p != NULL)
    {
        if (p->info.age <= x.age)
        {
            p = p->next;
        }
        else
        {
            return p->prev;
        }
    }
    return list.tail;
}

DNODE *insert(DLIST &list, DATA x)
{
    DNODE *p = find_largest_age(list, x);
    return insert_after(list, x, p);
}

int main()
{
    DLIST list;
    initialize(list);
    insert(list, {1, "Tran Thanh Tung", 20});
    insert(list, {2, "Le Minh Hai", 27});
    insert(list, {3, "Tran Hai Van", 26});
    insert(list, {4, "Ho Thanh Hieu", 23});
    insert(list, {5, "Nguyen Van An", 21});
    traverse(list);
    delete_all(list);
    return 0;
}