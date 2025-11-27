#include <stdio.h>

// Hàm tính căn bậc hai gần đúng với sai số không quá e
double sqrt(int n, double e) {
    double low = 0, high = n;

    while ((high - low) > e) {
        double mid = (low + high) / 2.0;
        if (mid * mid > n) {
            high = mid; // Nếu mid^2 lớn hơn n, tìm kiếm ở bên trái
        } else {
            low = mid;  // Nếu mid^2 nhỏ hơn hoặc bằng n, tìm kiếm ở bên phải
        }
    }

    return (low + high) / 2.0; // Trả về kết quả gần đúng
}

int main() {
    int n;
    double e = 0.0001;

    // Nhập số nguyên dương n
    printf("Nhập số nguyên dương n: ");
    scanf("%d", &n);

    // Gọi hàm tìm căn bậc hai gần đúng
    double result = sqrt(n, e);

    // In kết quả
    printf("Căn bậc hai gần đúng của %d là: %lf\n", n, result);
    printf("%lf\n", result*result);
    return 0;
}
