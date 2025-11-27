#include <stdio.h>

// Hàm tính số lượng tiền cần dùng
void countingMoney(int coins[], int n, int amount) {
    // Khởi tạo số lượng mỗi mệnh giá bằng 0
    int count[n] = {0};

    printf("Số tiền cần đổi: %d\n", amount);
    printf("Các mệnh giá được sử dụng:\n");

    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count[i]++;
        }
        if (count[i] > 0) {
            printf("Mệnh giá %d: %d tờ\n", coins[i], count[i]);
        }
    }

    if (amount == 0) {
        printf("Tổng số tờ/xu tiền cần dùng: ");
        int totalCount = 0;
        for (int i = 0; i < n; i++) {
            totalCount += count[i];
        }
        printf("%d\n", totalCount);
    } else {
        printf("Không thể đổi được số tiền!\n");
    }
}

int main() {
    int coins[] = {10000, 5000, 2000, 1000}; // Các mệnh giá tiền
    int n = sizeof(coins) / sizeof(coins[0]); // Số lượng các mệnh giá
    int amount;

    printf("Nhập số tiền cần đổi: ");
    scanf("%d", &amount);

    countingMoney(coins, n, amount);

    return 0;
}
