// 22301500-Võ Duy Bình 
#include "stack1.h"
#include <stdlib.h>
#include <string.h>

void decimalToHexadecimal(int decimal_number) {
    StackNode* stack = NULL;
    char hex_digits[] = "0123456789ABCDEF";
    while (decimal_number > 0) {
        push(&stack, decimal_number % 16);
        decimal_number /= 16;
    }
    printf("Số hexa: ");
    while (!isEmpty(stack)) {
        printf("%c", hex_digits[pop(&stack)]);
    }
    printf("\n");
}