#include <stdio.h>

// Hàm tìm phần tử lớn nhất trong mảng nhưng nhỏ hơn hoặc bằng x
int find_largest(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int result = -1; // Nếu không tìm thấy phần tử nào hợp lệ

    while (low <= high) {
        int mid = (low + high) / 2;

        // Nếu phần tử ở giữa nhỏ hơn hoặc bằng x, lưu lại vị trí và tìm tiếp ở bên phải
        if (arr[mid] <= x) {
            result = mid;
            low = mid + 1;  // Tìm tiếp ở nửa phải (phần lớn hơn)
        }
        // Nếu phần tử ở giữa lớn hơn x, tìm tiếp ở nửa trái
        else {
            high = mid - 1;
        }
    }

    return result; // Trả về vị trí nếu tìm thấy, nếu không thì trả về -1
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(int);
    int x = 10;

    // Gọi hàm tìm kiếm
    int index = find_largest(arr, n, x);

    if (index != -1) {
        printf("Phần tử lớn nhất <= %d là %d tại vị trí %d\n", x, arr[index], index);
    } else {
        printf("Không có phần tử nào <= %d\n", x);
    }

    return 0;
}
