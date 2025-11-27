#include "bstree.h"

int main(){
    TREE tree;
    initialize(tree);
    generate_bst(tree.root, 10, 1, 100);
    show(tree.root);
    printf("\n");
    NLR(tree.root);
    
    store_bst(tree.root, "bst.txt");
    printf("\nBST has been stored into the file\n");

    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}