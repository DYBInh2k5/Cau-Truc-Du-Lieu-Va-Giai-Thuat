
#include <stdio.h>

void f(int &a){
    a += 10;
    printf("a in function f(): %d\n", a);
}

int main(){
    int b = 100;
    f(b);//110
    printf("b after call f(): %d\n", b);//110
}

/*
a: tham so hinh thuc/doi so (argument)
b: tham so thuc (parameter)
khi thay doi a se anh huong den b vi a va b la mot bien
*/
1