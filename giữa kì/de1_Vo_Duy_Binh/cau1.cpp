// 22301500-Võ Duy Bình 
#include <main.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head_ref, int new_data) {
    Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void display(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

Node* createRandomEvenLinkedList(int n, int min_val, int max_val) {
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int even_number = (rand() % ((max_val - min_val) / 2 + 1)) * 2 + min_val;
        append(&head, even_number);
    }
    return head;
}