// 22301500-Võ Duy Bình 
#include "stack1.h"
#include <stdlib.h>
#include <string.h>

void dtob(int n, char *s){
    //1.Tạo stack
    STACK stack;
    initialize(stack);
    //2.Chia n cho 2 và đặt số dư vào stack
    do{
        push(stack, n % 2);
        n = n / 2;
    }while(n != 0);
    //3.Pop số dư từ stack tạo số nhị phân kết quả
    strcpy(s,"");
    int d;
    char temp[2];
    while(pop(stack, d)){        
        itoa(d, temp, 10);
        strcat(s , temp);
    }
}

int main(){
    char s[100];
    dtob(8, s);
    printf("%s\n", s);
    return 0;
}