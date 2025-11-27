#include "btree.h"

void display_at_left(NODE *p){
    if(p == NULL) return;
    if(p->left != NULL){
        printf("%d ", p->left->info);        
    }
    display_at_left(p->left);
    display_at_left(p->right);    
}

int main(){
	TREE tree;
	initialize(tree);
    generate_tree(tree.root, 3);
    show(tree.root,"","");
    printf("\n");
    display_at_left(tree.root);
    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}