#include "btree.h"

/**
 * @brief Thêm node x vào BST gốc p
 * 
 * @param p 
 * @param x 
 */
void insert_node(NODE *&p, DATA x){
    if(p==NULL){
        p = create_node(x);
    }else{
        if(p->info != x){
            if(x < p->info){
                insert_node(p->left, x);
            }else{
                insert_node(p->right, x);
            }
        }
    }
}

/**
 * @brief Tạo BST ngẫu nhiên
 * 
 * @param p: gốc
 * @param n: số node
 * @param min
 * @param max 
 */
void generate_bst(NODE *&p, int n, int min, int max){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        insert_node(p, rand() % (max - min + 1) + min);
    }
}

/**
 * @brief Tạo BST từ array vals[]
 * 
 * @param p 
 * @param vals 
 */
void generate_bst(NODE *&p, DATA vals[], int n){    
    for (int i = 0; i < n; i++)
    {
        insert_node(p, vals[i]);
    }    
}

/**
 * @brief Tìm node x trên BST gốc p
 * 
 * @param p 
 * @param x 
 * @return NODE* 
 */
NODE* search(NODE* p, DATA x){
    if(p == NULL) return NULL;
    if(p->info == x) return p;
    if(p->info > x){
        return search(p->left, x);
    }else{
        return search(p->right, x);
    }
}

/**
 * @brief Tìm node chứa info nhỏ nhất
 * 
 * @param p 
 * @return NODE* 
 */
NODE* get_min(NODE* p){
    if(p==NULL) return NULL;
    if(p->left==NULL){
        return p;
    }else{
        return get_min(p->left);
    }
}
//không dùng đệ qui
NODE* get_min2(NODE* p){
    if(p==NULL) return NULL;
    while(p->left != NULL){
        p = p->left;
    }
    return p;
}

/**
 * @brief Tìm node chứa info lớn nhất trên BST gốc p
 * 
 * @param p 
 * @return NODE* 
 */
NODE* get_max(NODE* p){
    if(p==NULL) return NULL;
    if(p->right==NULL){
        return p;
    }else{
        return get_max(p->right);
    }
}

//không dùng đệ qui
NODE* get_max2(NODE* p){
    if(p==NULL) return NULL;
    while(p->right != NULL){
        p = p->right;
    }
    return p;
}

/**
 * @brief Lưu BST gốc p vào file
 * 
 * @param p 
 * @param file 
 */
void store_bst(NODE* p, FILE *file){
    if(p != NULL){
        fprintf(file, "%d,", p->info);
        store_bst(p->left, file);
        store_bst(p->right, file);
    }
}

/**
 * @brief Lưu BST gốc p vào file
 * 
 * @param p 
 * @param filename 
 */
void store_bst(NODE* p, const char *filename){
    FILE *file = fopen(filename, "w");
    store_bst(p, file);
    fclose(file);
}

/**
 * @brief Khôi phục BST từ file
 * 
 * @param p 
 * @param filename 
 */
void restore_bst(NODE* &p, const char *filename){
    FILE *file = fopen(filename, "r");
    //đọc file để khôi phục các node
    DATA val;
    while(fscanf(file, "%d,", &val)==1){
        insert_node(p, val);
    }
    fclose(file);
}

/**
 * @brief Đếm số lần so sánh khi tìm node x
 * 
 * @param p 
 * @param x 
 * @param count : số lần so sánh
 * @return NODE* : địa chỉ của node x/NULL
 */
NODE* search_count(NODE* p, DATA x, int &count){
    count++;
    if(p == NULL) return NULL;
    count++;
    if(p->info == x) return p;
    count++;
    if(p->info > x){
        return search_count(p->left, x, count);
    }else{
        return search_count(p->right, x, count);
    }
}

/**
 * @brief Tìm pmin là node nhỏ nhất của cây con bên phải
 * để thay cho q
 * 
 * @param q : node cần xóa
 * @param pmin 
 */
void search_replace_min(NODE* &q, NODE* &pmin){
    if(pmin->left != NULL){
        //nếu pmin chưa phải là node nhỏ nhất
        //thì đi tiếp xuống nhánh trái
        search_replace_min(q, pmin->left);
    }else{
        //pmin là node nhỏ nhất
        q->info = pmin->info;
        q = pmin;
        pmin = pmin->right;
    }
}

/**
 * @brief Tìm pmax là node lớn nhất của cây con bên trái
 * để thay cho q
 * 
 * @param q : node cần xóa
 * @param pmax 
 */
void search_replace_max(NODE* &q, NODE* &pmax){
    if(pmax->right != NULL){
        //nếu pmax chưa phải là node lớn nhất
        //thì đi tiếp xuống nhánh phải
        search_replace_max(q, pmax->right);
    }else{
        //pmax là node lớn nhất
        q->info = pmax->info;
        q = pmax;
        pmax = pmax->left;
    }
}

/**
 * @brief Xóa node chứa x trong BST gốc p
 * 
 * @param p 
 * @param x 
 * @return true 
 * @return false 
 */
bool delete_node(NODE* &p, DATA x){
    if(p!=NULL){
        if(x < p->info){
            //đi tìm x ở nhánh bên trái để xóa
            return delete_node(p->left, x);
        }else if(x > p->info){
            //đi tìm x ở nhánh bên phải để xóa
            return delete_node(p->right, x);
        }else{//x == p->info
            NODE* q = p;
            if(is_leaf(p)){//p không có con
                p = NULL;
            }else if(p->left == NULL){//p chỉ có con bên phải
                p = p->right;
            }else if(p->right == NULL){//p chỉ có con bên trái
                p = p->left;
            }else{//p có đủ 2 con
                //C1
                //search_replace_min(q, q->right);  
                //C2
                search_replace_max(q, q->left); 
            }
            //giải phóng bộ nhớ cho node q
            delete q;
            return true;
        }
    }
    return false;
}
