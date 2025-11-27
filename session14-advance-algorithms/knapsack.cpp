#include <stdio.h>
#include <stdlib.h>

// Cấu trúc lưu thông tin vật phẩm
typedef struct {
    int weight;
    int value;
    double ratio; // value/weight
} Item;

// Hàm so sánh ratio
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemA->ratio > itemB->ratio) return -1;
    if (itemA->ratio < itemB->ratio) return 1;
    return 0;
}

// Hàm giải bài toán Knapsack
double knapsack(Item items[], int n, int W) {
    // Sắp xếp vật phẩm theo tỷ lệ value/weight giảm dần
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0; // Tổng giá trị
    for (int i = 0; i < n; i++) {
        if (W >= items[i].weight) {
            // Lấy toàn bộ vật phẩm
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Lấy một phần vật phẩm
            totalValue += items[i].ratio * W;
            break; // Ba lô đã đầy
        }
    }
    return totalValue;
}

int main() {
    int n, W;

    // Nhập số lượng vật phẩm và khả năng chứa của ba lô
    printf("Nhập số lượng vật phẩm: ");
    scanf("%d", &n);
    printf("Nhập khả năng chứa của ba lô: ");
    scanf("%d", &W);

    Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Nhập trọng lượng và giá trị của vật phẩm %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Giải bài toán Knapsack
    double maxValue = knapsack(items, n, W);
    printf("Tổng giá trị lớn nhất: %.2f\n", maxValue);

    return 0;
}
