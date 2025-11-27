#include "bstree.h"

int main(){
    TREE tree;
    initialize(tree);
    restore_bst(tree.root, "bst.txt");
    show(tree.root);

    int count = 0;
    DATA x = 41;
    NODE* p = search_count(tree.root, x, count);
    printf("Count: %d\n", count);
    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}