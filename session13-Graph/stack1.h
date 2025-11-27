//dùng danh sách đặc tạo stack
#include <stdio.h>

#define DATA int
#define N 100

typedef struct{
    int top;
    DATA a[N];
}STACK;

void initialize(STACK &s){
    s.top = -1;
}

bool is_empty(STACK s){
    return s.top == -1;
}

bool is_full(STACK s){
    return s.top == N - 1;
}

/**
 * @brief để value vào đỉnh stack s
 * 
 * @param s 
 * @param value 
 * @return true 
 * @return false 
 */
bool push(STACK &s, DATA value){
    if(!is_full(s)){
        //s.top++;
        //s.a[s.top] = value;
        s.a[++s.top] = value;
        return true;
    }
    return false;
}

bool pop(STACK &s, DATA &value){
    if(!is_empty(s)){
        //value = s.a[s.top];
        //s.top--;
        value = s.a[s.top--];
        return true;
    }
    return false;
}

bool peek(STACK &s, DATA &value){
    if(!is_empty(s)){
        value = s.a[s.top];
        return true;
    }
    return false;
}