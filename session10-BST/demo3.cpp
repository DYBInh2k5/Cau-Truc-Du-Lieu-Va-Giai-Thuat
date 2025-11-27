#include "bstree.h"

int main(){
    TREE tree;
    initialize(tree);
    DATA vals[] = {36, 3, 1, 42, 90, 74, 71, 53, 58, 76};
    int n = sizeof(vals)/sizeof(DATA);
    generate_bst(tree.root, vals, n);
    show(tree.root);
    LNR(tree.root);
    printf("\n");
    RNL(tree.root);
    DATA x = 100;
    NODE* p = search(tree.root, x);
    if(p != NULL){
        printf("\nFound %d in the tree at %u\n", x, p);
    }else{
        printf("\nNot found %d in the tree\n", x);
    }
    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}