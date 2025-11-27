#include "btree.h"

int main(){
	TREE tree;
	initialize(tree);
	tree.root = create_node(1);
	tree.root->left = create_node(2);
	tree.root->right = create_node(3);
	tree.root->left->left = create_node(4);
	tree.root->left->right = create_node(5);
	//cshow(tree.root,"","");
    show(tree.root,"","");
	NLR(tree.root);
	printf("\n");
	LNR(tree.root);
	printf("\n");
	LRN(tree.root);
	printf("\n");
	RLN(tree.root);
	printf("\n");
    return 0;
}