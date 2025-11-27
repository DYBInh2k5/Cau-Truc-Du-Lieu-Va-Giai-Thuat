#include "btree.h"

void display_leaf_path(NODE *p, char *path){
    //Nếu cây rỗng thì dừng lại
    if(p == NULL) return;
    //Cập nhật path
    sprintf(path, "%s-->%d", path, p->info);
    //Nếu p là node lá thì in path và dừng lại
    if(is_leaf(p)){
        printf("Path: %s\n", path);
    }else{//Nếu p không là node lá thì tìm tiếp
        //Lưu current path
        char current_path[100];
        strcpy(current_path, path);
        //Tìm node lá ở nhánh trái
        display_leaf_path(p->left , path);
        //Khôi phục current path
        strcpy(path, current_path);
        //Tìm node lá ở nhánh phải
        display_leaf_path(p->right, path);   
    }
}

void display_longest_path(NODE *p, char *path, int &length, int height){
    //Nếu cây rỗng thì dừng lại
    if(p == NULL) return;
    //Cập nhật path
    if(strcmp(path,"")==0){
        sprintf(path, "%d", p->info);
    }else{
        sprintf(path, "%s-->%d", path, p->info);
    }    
    //Nếu p là node lá thì in path và dừng lại
    if(is_leaf(p)){ 
        //Nếu path dài nhất thì in
        if(length == height - 1){
            printf("Length: %d - Path: %s\n", length, path);     
        }        
    }else{//Nếu p không là node lá thì tìm tiếp
        //Lưu current path
        char current_path[100];
        strcpy(current_path, path);
        //Tăng length lên 1 (đi xuống node con nên + 1)
        length++;
        //Lưu current length 
        int current_length = length;
        //Tìm node lá ở nhánh trái
        display_longest_path(p->left , path, length, height);
        //Khôi phục current path
        strcpy(path, current_path);
        //Khôi phục current length
        length = current_length;
        //Tìm node lá ở nhánh phải
        display_longest_path(p->right, path, length, height);
    }
}

/**
 * @brief Liệt kê đường đi từ node gốc p đến các node lá
 * 
 * @param p 
 */
void display_leaf_path(NODE* p){    
    int height = get_height(p);
    printf("All leaf paths:\n");
    char path[100];
    strcpy(path,"");    
    display_leaf_path(p, path);   
}

/**
 * @brief Liệt kê đường đi dài nhất từ node gốc p đến các node lá
 * 
 * @param p 
 */
void display_longest_path(NODE* p){
    int height = get_height(p);
    printf("\nTree's height: %d\n", height);
    printf("\nAll longest leaf paths:\n");
    char path[100];
    strcpy(path,"");
    int length = 0;
    display_longest_path(p, path, length, height);   
}

int main(){
	TREE tree;
	initialize(tree);
    generate_tree(tree.root, 4);
    show(tree.root);
    //Liệt kê đường đi từ node gốc đến các node lá
    display_leaf_path(tree.root);
    //Liệt kê đường đi dài nhất từ node gốc đến các node lá
    display_longest_path(tree.root);
    //giải phóng bộ nhớ
    delete_tree(tree.root);
    return 0;
}