// 22301500-Võ Duy Bình 
#include <stdio.h>

#define DATA int

typedef struct{
    int top;
    DATA a[N];
}STACK;

void intialize(STACK &s){
    s.top = -1;
}

bool is_empty(STACK &s){
    return s.top == -1;
}
bool is_full(STACK &s){
    return s.top == N-1;
}

bool push(STACK &s,DATA value){
    if (list_full(s){
        //s.top++;
        //s.a[s.top]=value;
        s.a[++s.top]=value;

    }
        return true;
    return false;
}
bool pop(STACK &s, DATA &value){
    if ( !IsEmpty(s) ) {

        //value = s.a[s.top];
        //s.top--;

        value = s.a[s.top--]
        return true;
    }
    return false;
}
bool Peek(STACK &s, DATA value) {
    if ( !IsEmpty(s) ) {
        value = s.a[s.top];
        return true;
    }
    return false;
}






