// 22301500-Võ Duy Bình 
#include <main.h>
#include <stdlib.h>
#include <time.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm để thêm một nút vào danh sách liên kết đơn theo thứ tự tăng dần
void insertInSortedOrder(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // Nếu danh sách rỗng hoặc nút mới nhỏ hơn nút đầu tiên
    if (*head == NULL || (*head)->data > data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        // Tìm vị trí để chèn nút mới
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Hàm để tạo danh sách liên kết đơn chứa n số nguyên chẵn ngẫu nhiên tăng dần
Node* createSortedEvenList(int n, int min, int max) {
    Node* head = NULL;
    int count = 0;
    srand(time(0));

    while (count < n) {
        int num = rand() % (max - min + 1) + min;
        if (num % 2 == 0) { // Kiểm tra xem số có phải là số chẵn không
            insertInSortedOrder(&head, num);
            count++;
        }
    }
    return head;
}

