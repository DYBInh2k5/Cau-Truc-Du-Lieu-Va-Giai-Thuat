#include "student-avltree.h"

int main(){
    AVLTREE avlt;
    STUDENT students[] = {
        {1,"Nguyen Thanh Hai", 7.5},
        {2,"Tran Thanh Tung", 9.5},
        {3,"Le Minh Chien", 6.5},
        {4,"Pham Tan Hung", 8.5},
        {5,"Ly Thu Thuy", 6.5},
    };
    int n = sizeof(students)/sizeof(STUDENT);
    generate_AVLT(avlt, students, n);
    show(avlt);
    delete_tree(avlt);
    return 0;
}