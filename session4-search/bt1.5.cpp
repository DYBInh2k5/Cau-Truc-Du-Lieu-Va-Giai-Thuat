#include <stdio.h>
#include <string.h>

// Hàm tìm vị trí xuất hiện của substr trong str
int find_string(char str[], char substr[]) {
    int len_str = strlen(str);
    int len_substr = strlen(substr);

    // Duyệt qua chuỗi mẹ để tìm chuỗi con
    for (int i = 0; i <= len_str - len_substr; i++) {
        int j;
        // Kiểm tra nếu các ký tự từ vị trí i trùng với chuỗi con
        for (j = 0; j < len_substr; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        // Nếu duyệt hết chuỗi con mà không bị break, trả về vị trí i
        if (j == len_substr) {
            return i; // Trả về vị trí đầu tiên xuất hiện chuỗi con
        }
    }
    return -1; // Không tìm thấy chuỗi con
}

int main() {
    char str[100] = "Chuong trinh C";
    char substr[100] = "rinh";

    // Tìm vị trí xuất hiện của chuỗi con
    int result = find_string(str, substr);

    if (result != -1) {
        printf("Chuỗi con xuất hiện tại vị trí: %d\n", result);
    } else {
        printf("Chuỗi con không xuất hiện trong chuỗi mẹ.\n");
    }

    return 0;
}
