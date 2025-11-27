// 22301500-Võ Duy Bình 
#include "doubly-linked-list.h"
int main() {
    srand(time(0)); // Khởi tạo seed cho random

    int n = 10; // Số lượng số nguyên chẵn
    int min_val = 0;
    int max_val = 100;

    // Tạo danh sách liên kết đơn chứa n số nguyên chẵn ngẫu nhiên
    Node* even_linked_list = createRandomEvenLinkedList(n, min_val, max_val);
    printf("Danh sách liên kết đơn chứa n số nguyên chẵn ngẫu nhiên:\n");
    display(even_linked_list);

    // Tạo danh sách liên kết đơn chứa n số nguyên chẵn ngẫu nhiên tăng dần
    Node* sorted_even_linked_list = createSortedEvenLinkedList(n, min_val, max_val);
    printf("Danh sách liên kết đơn chứa n số nguyên chẵn ngẫu nhiên tăng dần:\n");
    display(sorted_even_linked_list);

    // Chuyển đổi số thập phân sang nhị phân
    int decimal_number = 10;
    decimalToBinary(decimal_number);

    // Chuyển đổi số thập phân sang hexa
    decimal_number = 255;
    decimalToHexadecimal(decimal_number);

    return 0;
}