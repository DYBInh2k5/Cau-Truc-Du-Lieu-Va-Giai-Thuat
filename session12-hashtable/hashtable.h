#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 5

typedef struct Node {
    int key;
    int value;
    Node *next;
} Node;

typedef struct HashTable {
    Node *table[TABLE_SIZE] = {NULL};//gán NULL cho tất cả các phần tử trong table
} HashTable;

int hash(int key){
    return key % TABLE_SIZE;
}

void insert(HashTable *ht, int key, int value){
    //xác định index của phần tử cần thêm
    int index = hash(key);
    //tạo node mới chứa (key, value)
    Node *p = (Node*)malloc(sizeof(Node));
    p->key = key;
    p->value = value;
    //gắn node mới vào đầu dslk tại vị trí index
    p->next = ht->table[index];
    ht->table[index] = p;
}

Node *search(HashTable *ht, int key){
    //xác định index của phần tử cần thêm
    int index = hash(key);
    //duyệt danh sách liên kết tại vị trí index để tìm phần tử có khóa cần tìm
    Node *p = ht->table[index];
    while(p != NULL){
        if(p->key == key){
            //tìm thấy
            return p;
        }
        p = p->next;
    }
    //không tìm thấy
    return NULL;
}

bool remove(HashTable *ht, int key){
    //xác định index của phần tử cần thêm
    int index = hash(key);
    //duyệt danh sách liên kết tại vị trí index để tìm phần tử có khóa cần xóa
    Node *current = ht->table[index];
    Node *previous = NULL;
    while(current != NULL){
        if(current->key == key){
            //nếu tìm thấy node cần xóa thì tiến hành xóa            
            if(previous == NULL){
                //nếu node cần xóa là node đầu tiên
                ht->table[index] = current->next;
            }else{
                //nếu node cần xóa không là node đầu tiên
                previous->next = current->next;
            }
            //giải phóng bộ nhớ của node cần xóa
            free(current);
            return true;
        }
        //nếu chưa tìm thấy node cần xóa thì dịch chuyển previous & current sang node kế tiếp
        previous = current;
        current = current->next;
    }
    //tìm không thấy node cần xóa
    return false;
}

void list_display(Node *head){
    Node *p = head;
    while(p != NULL && p->next != NULL){
        printf("(%d,%d)->", p->key, p->value);
        p = p->next;
    }
    //in node cuối cùng
    if(p != NULL){
        printf("(%d,%d)\n", p->key, p->value);
    }
}

void display(HashTable *ht){
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Index: %d: ", i);
        list_display(ht->table[i]);
    } 
}

void list_remove(Node *&head){
    while(head != NULL){
        Node *p = head;
        head = head->next;
        free(p);
    }
}

/**
 * @brief Giải phóng bộ nhớ chứa các dslk trong ht
 * 
 * @param ht 
 */
void remove(HashTable *ht){
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        //giải phóng bộ nhớ chứa dslk thứ i
        list_remove(ht->table[i]);
    }
    
}

/**
 * @brief Lấy value tương ứng với key
 * 
 * @param ht 
 * @param key 
 * @return int : value/-1 (nếu key không tồn tại)
 */
int get(HashTable *ht, int key){
    Node *p = search(ht, key);
    if(p != NULL){
        return p->value;
    }else{
        return -1;
    }
}