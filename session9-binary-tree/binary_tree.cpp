#include "btree.h"

int main(){
	TREE tree;
	initialize(tree);
    generate_tree(tree.root, 4);
    show(tree.root,"","");
	NLR(tree.root);
    printf("\n");
    BFS(tree.root);
    printf("\n");
    traverse_by_level(tree.root);
    printf("\n");
    printf("Number of nodes: %d\n", count_nodes(tree.root));
    printf("Number of leaves: %d\n", count_leaf_nodes(tree.root));
    printf("Number of internal nodes: %d\n", count_internal_nodes(tree.root));
    printf("Height of the tree: %d\n", get_height(tree.root));
    display_at_level(tree.root, 1);    
    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}