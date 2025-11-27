#include "btree.h"

int main(){
	TREE tree;
	initialize(tree);
    generate_tree(tree.root, 4);
    show(tree.root);    
    store(tree.root, "tree.txt");
    printf("The tree has been stored into the file\n");
    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}