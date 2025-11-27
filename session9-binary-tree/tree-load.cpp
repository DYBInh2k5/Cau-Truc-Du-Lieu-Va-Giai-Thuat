#include <stdio.h>
#include "btree.h"

int main(){
    TREE tree;
	initialize(tree);
    load(tree.root, "tree.txt");
    show(tree.root);
    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}