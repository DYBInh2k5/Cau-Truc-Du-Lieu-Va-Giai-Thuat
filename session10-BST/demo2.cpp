#include "bstree.h"

int main(){
    TREE tree;
    initialize(tree);
    generate_bst(tree.root, 10, 1, 100);
    show(tree.root);
    LNR(tree.root);
    printf("\n");
    RNL(tree.root);
    printf("\n");
    NLR(tree.root);
    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}