#include "bstree.h"

int main(){
    TREE tree;
    initialize(tree);
    insert_node(tree.root, 50);
    insert_node(tree.root, 60);
    insert_node(tree.root, 40);
    insert_node(tree.root, 30);
    insert_node(tree.root, 90);
    show(tree.root);
    LNR(tree.root);
    printf("\n");
    RNL(tree.root);
    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}