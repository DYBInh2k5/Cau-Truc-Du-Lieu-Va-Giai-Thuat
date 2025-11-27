#include "bstree.h"

int main(){
    TREE tree;
    initialize(tree);
    generate_bst(tree.root, 10, 1, 100);
    show(tree.root);
    LNR(tree.root);
    printf("\n");
    RNL(tree.root);

    NODE* p = get_min(tree.root);
    printf("\nMin value: %d\n", p->info);

    p = get_min2(tree.root);
    printf("Min value: %d\n", p->info);
    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}