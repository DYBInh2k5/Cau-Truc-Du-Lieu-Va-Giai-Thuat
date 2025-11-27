#include "btree.h"

int count_at_level(NODE *p, int level){
    if(p == NULL) return 0;
    if(level == 0){
        return 1;
    }else{
        int lelf_count = count_at_level(p->left, level - 1);
        int right_count = count_at_level(p->right, level - 1);
        return lelf_count + right_count;
    }
}

int main(){
	TREE tree;
	initialize(tree);
    generate_tree(tree.root, 5);
    show(tree.root,"","");
    printf("\n");
    printf("Number of nodes: %d\n", count_at_level(tree.root, 4));  
    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}