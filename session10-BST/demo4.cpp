#include "bstree.h"

int main(){
    TREE tree;
    initialize(tree);
    DATA vals[] = {60, 36, 20, 45, 40, 42, 90, 74, 71, 53, 56, 76, 10, 25, 24};
    int n = sizeof(vals)/sizeof(DATA);
    generate_bst(tree.root, vals, n);
    show(tree.root);
    //DATA x = 24;//không có con
    //DATA x = 90;//chỉ có con bên trái
    //DATA x = 53;//chỉ có con bên phải
    DATA x = 36;//có đủ 2 con
    delete_node(tree.root, x);
    show(tree.root);
    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}