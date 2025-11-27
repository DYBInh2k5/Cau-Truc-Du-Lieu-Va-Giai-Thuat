#include <stdio.h>

// Hàm tìm vị trí xuất hiện đầu tiên của phần tử x
int find_first(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == x) {
            result = mid; // Lưu lại kết quả hiện tại
            high = mid - 1; // Tìm tiếp ở nửa trái để tìm vị trí đầu tiên
        } else if (arr[mid] < x) {
            low = mid + 1; // Nếu phần tử ở giữa nhỏ hơn x, tìm tiếp ở nửa phải
        } else {
            high = mid - 1; // Nếu phần tử ở giữa lớn hơn x, tìm tiếp ở nửa trái
        }
    }

    return result;
}

// Hàm tìm vị trí xuất hiện cuối cùng của phần tử x
int find_last(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == x) {
            result = mid; // Lưu lại kết quả hiện tại
            low = mid + 1; // Tìm tiếp ở nửa phải để tìm vị trí cuối cùng
        } else if (arr[mid] < x) {
            low = mid + 1; // Nếu phần tử ở giữa nhỏ hơn x, tìm tiếp ở nửa phải
        } else {
            high = mid - 1; // Nếu phần tử ở giữa lớn hơn x, tìm tiếp ở nửa trái
        }
    }

    return result;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    int x = 50;

    // Tìm vị trí đầu tiên và cuối cùng của x
    int first = find_first(arr, n, x);
    int last = find_last(arr, n, x);

    // Kết quả
    if (first != -1) {
        printf("Vị trí đầu tiên: %d, Vị trí cuối cùng: %d\n", first, last);
    } else {
        printf("Không tìm thấy phần tử %d trong mảng\n", x);
    }

    return 0;
}
