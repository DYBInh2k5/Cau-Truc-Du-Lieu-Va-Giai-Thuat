#include "btree.h"

NODE* find_left_most(NODE *p){
    while(p != NULL && p->left != NULL){
        p = p->left;
    }
    return p;
}

void insert_left_most(NODE *&p, DATA x){
    NODE *q = create_node(x);
    if(p==NULL){
        p = q;
    }else{
        NODE *lm = find_left_most(p);
        lm->left = q;
    }
}

/**
 * @brief Tìm đường đi từ node gốc p đến node x
 * 
 * @param p 
 * @param x 
 * @param path 
 * @return NODE* 
 */
NODE* get_path(NODE *p, DATA x, char *path){
    //Nếu không tìm thấy node x
    if(p == NULL) return NULL;
    //Cập nhật path
    sprintf(path, "%s-->%d", path, p->info);
    //Nếu p là node x
    if(p->info==x){
        return p;
    }else{//Nếu p không là node x
        //Lưu current path
        char current_path[100];
        strcpy(current_path, path);
        //Tìm node x ở nhánh trái
        NODE* q = get_path(p->left , x, path);
        //Nếu không tìm thấy node x ở nhánh trái thì
        if(q == NULL){
            //Khôi phục current path
            strcpy(path, current_path);
            //Tìm node x ở nhánh phải
            q = get_path(p->right, x, path);
        }  
        return q;      
    }
}

int main(){
	TREE tree;
	initialize(tree);
    load(tree.root, "tree.txt");    
    show(tree.root);

    char path[100];

    strcpy(path,"");
    get_path(tree.root, 35, path);
    printf("Path: %s\n", path);

    strcpy(path,"");
    get_path(tree.root, 37, path);
    printf("Path: %s\n", path);

    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}