#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include "queue.h"
#include "types.h"
#include <iostream>
using namespace std;

void initialize(TREE &tree)
{
    tree.root = NULL;
}

NODE *create_node(int x)
{
    NODE *p = new NODE;
    if (p != NULL)
    {
        p->info = x;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

void cshow(NODE *node, const char *prefix, const char *childrenPrefix)
{
    char childrenPrefix1[100];
    char childrenPrefix2[100];
    char childrenPrefix3[100];
    char childrenPrefix4[100];
    strcpy(childrenPrefix1, childrenPrefix);
    strcpy(childrenPrefix2, childrenPrefix);
    strcpy(childrenPrefix3, childrenPrefix);
    strcpy(childrenPrefix4, childrenPrefix);

    strcat(childrenPrefix1, "+-- ");
    strcat(childrenPrefix2, "|   ");
    strcat(childrenPrefix3, "+-- ");
    strcat(childrenPrefix4, "    ");

    if (node == NULL)
        return;
    printf("%s%d\n", prefix, node->info);
    if (node->right == NULL)
    {
        cshow(node->left, childrenPrefix1, childrenPrefix4);
        return;
    }
    cshow(node->left, childrenPrefix1, childrenPrefix2);
    cshow(node->right, childrenPrefix3, childrenPrefix4);
}

void show(NODE *node, string prefix, string childrenPrefix)
{
    if (node == NULL){
    	return;
	}        
    printf("%s%d\n", prefix.c_str(), node->info);
    if(node->left==NULL){
    	show(node->right, childrenPrefix + "R-- ", childrenPrefix + "    ");
    	return;
	}
    show(node->right, childrenPrefix + "R-- ", childrenPrefix + "|   ");
    show(node->left , childrenPrefix + "L-- ", childrenPrefix + "    ");    
}

void show(NODE *root){
    show(root,"","");
    printf("\n");
}

/**
 * @brief Duyệt cây gốc p theo phương pháp NLR
 *
 * @param p
 */
void NLR(NODE *p)
{
    if (p != NULL)
    {
        printf("%d ", p->info);
        NLR(p->left);
        NLR(p->right);
    }
}

/**
 * @brief Duyệt cây gốc p theo phương pháp LRN
 *
 * @param p
 */
void LRN(NODE *p)
{
    if (p != NULL)
    {
        NLR(p->left);
        NLR(p->right);
        printf("%d ", p->info);
    }
}

/**
 * @brief Duyệt cây gốc p theo phương pháp LNR
 *
 * @param p
 */
void LNR(NODE *p)
{
    if (p != NULL)
    {
        LNR(p->left);
        printf("%d ", p->info);
        LNR(p->right);
    }
}

void RNL(NODE *p)
{
    if (p != NULL)
    {                
        RNL(p->right);
        printf("%d ", p->info);
        RNL(p->left);
    }
}

/**
 * @brief Duyệt cây gốc p theo phương pháp RLN
 *
 * @param p
 */
void RLN(NODE *p)
{
    if (p != NULL)
    {
        NLR(p->right);
        NLR(p->left);
        printf("%d ", p->info);
    }
}

/**
 * @brief Breadth First Search - duyệt cây gốc p theo mức (Traverse by Level)
 * 
 * @param p 
 */
void BFS(NODE *p){
    //1. Khởi tạo hàng đợi queue
    QUEUE queue;
    initialize(queue);
    //2. Để node p vào queue
    if(p != NULL) enqueue(queue, p);
    //3. Trong khi queue khác rỗng thì thực hiện:
    while(!is_empty_queue(queue)){    
        //3.1. Lấy node p từ queue    
        dequeue(queue, p);
        //3.2. Duyệt node p
        printf("%d ", p->info);
        //3.3. Thêm node con của node p vào queue nếu node con khác rỗng
        if(p->left != NULL) enqueue(queue, p->left);
        if(p->right != NULL) enqueue(queue, p->right);
    }
}

/**
 * @brief Tạo cây ngẫu nhiên đầy đủ có độ sâu d
 * 
 * @param p 
 * @param d 
 */
void generate_sub_full_tree(NODE *&p, int d){    
    if(d!=0){
        p = create_node(rand() % 100 + 1);
        generate_sub_full_tree(p->left, d-1);
        generate_sub_full_tree(p->right, d-1);
    }
}

void generate_full_tree(NODE *&p, int d){
    srand(time(NULL));
    generate_sub_full_tree(p, d);
}

/**
 * @brief Tạo cây ngẫu nhiên gốc p có độ sâu d
 * 
 * @param p 
 * @param d 
 */
void generate_sub_tree(NODE *&p, int d){    
    if(d>0){
        p = create_node(rand() % 100 + 1);
        int n = rand() % 36;
        if(n<5){
            generate_sub_tree(p->left, d-2);
            generate_sub_tree(p->right, d-1);
        }else if(n<10){
            generate_sub_tree(p->left, d-1);
            generate_sub_tree(p->right, d-2);
        }else if(n<15){
            generate_sub_tree(p->left, d-1);
        }else if(n<20){
            generate_sub_tree(p->right, d-1);
        }else{
            generate_sub_tree(p->left, d-1);
            generate_sub_tree(p->right, d-1);
        }
    }
}

void generate_tree(NODE *&p, int d){
    srand(time(NULL));
    generate_sub_tree(p, d);
}

/**
 * @brief Giải phóng bộ nhớ của cây gốc p
 * 
 * @param p 
 */
void delete_tree(NODE *&p){
    if(p!=NULL){
        delete_tree(p->left);
        delete_tree(p->right);
        delete p;
    }
}

/**
 * @brief kiểm tra p có là node lá hay không
 * 
 * @param p 
 * @return true 
 * @return false 
 */
bool is_leaf(NODE *p){
    return p->left == NULL && p->right == NULL;
}

/**
 * @brief Đếm số node lá của cây p
 * 
 * @param p 
 * @return int 
 */
int count_leaf_nodes(NODE *p){
    if(p == NULL){
        return 0;
    }
    if(is_leaf(p)){
        return 1;
    }
    return count_leaf_nodes(p->left) + count_leaf_nodes(p->right);
}

/**
 * @brief đếm số node của cây gốc p
 * 
 * @param p 
 * @return int 
 */
int count_nodes(NODE *p){
    if(p == NULL) return 0;
    return 1 + count_nodes(p->left) + count_nodes(p->right);
}

/**
 * @brief đếm số node trong của cây gốc p (không phải gốc và lá)
 * 
 * @param p 
 * @return int 
 */
int count_internal_nodes(NODE *p){
    if(p==NULL) return 0;
    // -1 == trừ đi node gốc
    return max(count_nodes(p) - count_leaf_nodes(p) - 1, 0);
}

/**
 * @brief Tính chiều cao của cây gốc p
 * 
 * @param p 
 * @return int 
 */
int get_height(NODE *p){
    if(p==NULL) return 0;
    return max(get_height(p->left), get_height(p->right)) + 1;
}

/**
 * @brief Liệt kê các nodes ở mức level
 * 
 * @param p 
 * @param level 
 */
void display_at_level(NODE *p, int level){
    if(p == NULL) return;
    if(level == 0){
        printf("%d ", p->info);
    }else{
        display_at_level(p->left, level - 1);
        display_at_level(p->right, level - 1);
    }
}

/**
 * @brief Duyệt cây gốc p theo mức (BFS)
 * 
 * @param p 
 */
void traverse_by_level(NODE *p){
    int height = get_height(p);
    for (int i = 0; i < height; i++)
    {
        display_at_level(p, i);
    }
}

/**
 * @brief Lấy info của node p
 * 
 * @param p 
 * @return DATA 
 */
DATA info(NODE *p){
    return (p != NULL)? p->info: -1;
}

/**
 * @brief Lưu cây gốc p vào file (duyệt theo mức và lưu thông tin)
 * 
 * @param p 
 * @param filename 
 */
void store(NODE *p, const char *filename){
    //0. Mở file để ghi
    FILE *file = fopen(filename, "w");
    //1. Khởi tạo hàng đợi queue
    QUEUE queue;
    initialize(queue);
    //2. Để node p vào queue
    if(p != NULL) enqueue(queue, p);
    //3. Trong khi queue khác rỗng thì thực hiện:
    while(!is_empty_queue(queue)){    
        //3.1. Lấy node p từ queue    
        dequeue(queue, p);
        //3.2. Duyệt node p
        fprintf(file, "%d,%d,%d\n", info(p), info(p->left), info(p->right));
        //3.3. Thêm node con của node p vào queue nếu node con khác rỗng
        if(p->left != NULL) enqueue(queue, p->left);
        if(p->right != NULL) enqueue(queue, p->right);
    }
    //4. Đóng file
    fclose(file);
}

/**
 * @brief Khôi phục cây gốc root từ file
 * 
 * @param root 
 * @param filename 
 */
void load(NODE *&root, const char *filename){
    //1. Khởi tạo hàng đợi queue
    QUEUE queue;
    initialize(queue);
    //2. Mở file để đọc file
    FILE *file = fopen(filename, "r");
    //3. Đọc dòng đầu tiên trong file
    int val1, val2, val3;
    if (fscanf(file, "%d,%d,%d\n", &val1, &val2, &val3)!=3) return;
    //4. Khởi tạo node gốc và con trái, con phải
    NODE *p;
    //4.1. Khởi tạo node root
    if(val1!=-1){
        root = p = create_node(val1);
    }
    //4.2. Nếu root có con trái thì:
    if(val2!=-1){
        p->left = create_node(val2);
        enqueue(queue, p->left);
    }
    //4.3. Nếu root có con phải thì:
    if(val3!=-1){
        p->right = create_node(val3);
        enqueue(queue, p->right);
    }
    //5. Trong khi chưa hết file thì thực hiện:
    while (fscanf(file, "%d,%d,%d\n", &val1, &val2, &val3)==3){
        //5.1. Lấy node p từ queue    
        dequeue(queue, p);
        //Kiểm tra p->info == val1
        assert(p->info == val1);
        //5.2. Nếu p có con trái thì:
        if(val2!=-1){
            p->left = create_node(val2);
            enqueue(queue, p->left);
        }
        //5.3. Nếu p có con phải thì:
        if(val3!=-1){
            p->right = create_node(val3);
            enqueue(queue, p->right);
        }
    }
    //6. Đóng file
    fclose(file);
}


