#include "bstree.h"

int main(){
    TREE tree;
    initialize(tree);
    restore_bst(tree.root, "bst.txt");
    show(tree.root);
    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}