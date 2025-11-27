#include "score-student-avltree.h"

int main(){
    AVLTREE avlt;
    STUDENT students[] = {
        {1,"Nguyen Thanh Hai", 7.5},
        {2,"Tran Thanh Tung", 9.5},
        {3,"Le Minh Chien", 6.5},
        {4,"Pham Tan Hung", 8.5},
        {5,"Ly Thu Thuy", 6.5},
        {6,"Tran Minh Tung", 6.5},
        {7,"Ho Thanh Hao", 8.5},
        {8,"Huynh Hai Lam", 8.5},
        {9,"Pham Tat Thang", 8.5},
        {10,"Ly Thanh Minh", 9.5},
    };
    int n = sizeof(students)/sizeof(STUDENT);
    generate_AVLT(avlt, students, n);
    show(avlt);
    LNR(avlt);
    RNL(avlt);
    delete_tree(avlt);
    return 0;
}