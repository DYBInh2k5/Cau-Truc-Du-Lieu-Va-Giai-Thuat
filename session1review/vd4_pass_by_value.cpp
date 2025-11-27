
#include <stdio.h>

void f(int a){
    a += 10;
    printf("a in function f(): %d\n", a);
}

int main(){
    int b = 100;
    f(b);//110
    printf("b after call f(): %d\n", b);//100
}

/*
a: tham so hinh thuc/doi so (argument)
b: tham so thuc (parameter)
khi thay doi a khong anh huong den b vi a va b la hai bien khac nhau
*/
1