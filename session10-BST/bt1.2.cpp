#include "bstree.h"

int main(){
    TREE tree;
    initialize(tree);
    generate_bst(tree.root, 10, 1, 100);
    show(tree.root);
    LNR(tree.root);
    printf("\n");
    RNL(tree.root);

    NODE* p = get_max(tree.root);
    printf("\nMax value: %d\n", p->info);

    p = get_max2(tree.root);
    printf("Max value: %d\n", p->info);
    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}