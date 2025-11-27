#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node cho danh sách liên kết
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm thêm phần tử vào danh sách liên kết
void insert(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Hàm xóa danh sách liên kết
void clear(Node** head) {
    Node* current = *head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

// Hàm lấy chữ số tại vị trí digit_pos từ phải sang
int get_digit(int num, int digit_pos) {
    return (num / digit_pos) % 10;
}

// Hàm Radix Sort sử dụng bảng băm
void radix_sort_with_hash_table(int arr[], int n) {
    if (n <= 0) return;

    // Tìm số lớn nhất trong mảng để biết số chữ số lớn nhất
    int max_num = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }

    // Tạo bảng băm (10 bucket)
    Node* buckets[10] = {NULL};

    // Sắp xếp theo từng chữ số
    int digit_pos = 1;
    while (max_num / digit_pos > 0) {
        // Phân loại vào bucket
        for (int i = 0; i < n; i++) {
            int digit = get_digit(arr[i], digit_pos);
            insert(&buckets[digit], arr[i]);
        }

        // Gom lại các số từ các bucket vào mảng
        int index = 0;
        for (int i = 0; i < 10; i++) {
            Node* current = buckets[i];
            while (current != NULL) {
                arr[index++] = current->data;
                current = current->next;
            }
            // Xóa bucket sau khi sử dụng
            clear(&buckets[i]);
        }

        // Chuyển sang chữ số tiếp theo
        digit_pos *= 10;
    }
}

// Hàm in mảng
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66, 1234, 2568};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mảng ban đầu: ");
    print_array(arr, n);

    radix_sort_with_hash_table(arr, n);

    printf("Mảng sau khi sắp xếp: ");
    print_array(arr, n);

    return 0;
}
