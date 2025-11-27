#include <stdio.h>
#include <string.h>
#include <iostream>
#include "singly-linked-list.h"
#include "types.h"
using namespace std;

#define LH -1 // cây con trái cao hơn
#define EH 0  // hai cây con bằng nhau
#define RH 1  // cây con phải cao hơn

#define KEY double

typedef struct AVLNODE
{
    KEY score;
    LIST list;//chứa danh sách sinh viên có score giống nhau
    AVLNODE *left;
    AVLNODE *right;
    char BF;
} AVLNODE;

typedef struct AVLTREE
{
    AVLNODE *root;
} AVLTREE;

void initialize(AVLTREE &tree)
{
    tree.root = NULL;
}

AVLNODE *create_node(STUDENT student)
{
    AVLNODE *p = new AVLNODE;
    if (p != NULL)
    {
        p->score = student.score;
        initialize(p->list);
        insert_head(p->list, student);
        p->left = NULL;
        p->right = NULL;
        p->BF = EH;
    }
    return p;
}

/**
 * @brief Quay phải tại T (TH1: LL)
 *
 * @param T
 */
void right_rotate(AVLNODE *&T)
{
    AVLNODE *T1 = T->left;
    T->left = T1->right; // 1
    T1->right = T;       // 2
    T = T1;
}

/**
 * @brief Quay trái tại T (TH3: RR)
 *
 * @param T
 */
void left_rotate(AVLNODE *&T)
{
    AVLNODE *T1 = T->right;
    T->right = T1->left; // 1
    T1->left = T;        // 2
    T = T1;
}

/**
 * @brief Xử lý trường hợp cây gốc T lệch trái (TH1: LL, TH2: LR)
 *
 * @param T
 */
void left_balance(AVLNODE *&T)
{
    switch (T->left->BF)
    {
    case LH: // TH1: LL
        right_rotate(T);
        // điều chỉnh BF
        T->BF = EH;
        T->right->BF = EH;
        break;
    case RH: // TH2: LR
        left_rotate(T->left);
        right_rotate(T);
        // điều chỉnh BF
        switch (T->BF) // T chinh la R1
        {
        case EH: // blue == red
            T->left->BF = EH;
            T->right->BF = EH;
            break;
        case LH: // blue longer
            T->left->BF = EH;
            T->right->BF = RH;
            break;
        case RH: // Red longer
            T->left->BF = LH;
            T->right->BF = EH;
            break;
        }
        T->BF = EH;
        break;
    }
}

/**
 * @brief Xử lý trường hợp cây gốc T lệch phải (TH3: RR, TH4: RL)
 *
 * @param p
 */
void right_balance(AVLNODE *&T)
{
    switch (T->right->BF)
    {
    case RH: // TH3: RR
        left_rotate(T);
        // điều chỉnh BF
        T->BF = EH;
        T->left->BF = EH;
        break;
    case LH: // TH4: RL
        right_rotate(T->right);
        left_rotate(T);
        // điều chỉnh BF
        switch (T->BF) // T chinh la L1
        {
        case EH: // blue == red
            T->left->BF = EH;
            T->right->BF = EH;
            break;
        case LH: // blue longer
            T->left->BF = EH;
            T->right->BF = RH;
            break;
        case RH: // red longer
            T->left->BF = LH;
            T->right->BF = EH;
            break;
        }
        T->BF = EH;
        break;
    }
}

/**
 * @brief Thêm node chứa x vào AVLT gốc p
 *
 * @param p
 * @param x
 * @return int
    -1: thêm không thành công do thiếu bộ nhớ
     0: x đã tồn tại trong cây
     1: thêm thành công và không làm tăng chiều cao cây
     2: thêm thành công và làm tăng chiều cao cây
 */
int insert_node(AVLNODE *&p, STUDENT student)
{
    int res;
    // nếu cây rỗng
    if (p == NULL)
    {
        p = create_node(student);
        if (p == NULL)
        {
            return -1; // thêm không thành công do thiếu bộ nhớ
        }
        return 2; // thêm thành công và làm tăng chiều cao cây
    }
    else // nếu cây khác rỗng
    {
        if (p->score == student.score)
        {
            // thêm student vào p->list
            insert_head(p->list, student);
            return 0; // x đã tồn tại trong cây
        }
        else if (p->score > student.score)
        {
            res = insert_node(p->left, student);
            if (res < 2)
            {
                return res;
            }
            switch (p->BF)
            {
            case EH:
                p->BF = LH;
                return 2;
            case LH:
                left_balance(p);
                return 1;
            case RH:
                p->BF = EH;
                return 1;
            }
        }
        else // p->score < student.score
        {
            res = insert_node(p->right, student);
            if (res < 2)
            {
                return res;
            }
            switch (p->BF)
            {
            case EH:
                p->BF = RH;
                return 2;
            case LH:
                p->BF = EH;
                return 1;
            case RH:
                right_balance(p);
                return 1;
            }
        }
    }
    return res;
}

/**
 * @brief Giải phóng bộ nhớ của AVLT gốc p
 *
 * @param p
 */
void delete_tree(AVLNODE *&p)
{
    if (p != NULL)
    {
        delete_tree(p->left);
        delete_tree(p->right);
        delete p;
    }
}

/**
 * @brief Giải phóng bộ nhớ chứa AVLT
 * 
 * @param tree 
 */
void delete_tree(AVLTREE &tree){
    delete_tree(tree.root);
}

/**
 * @brief In AVLT gốc p
 *
 * @param p
 * @param prefix
 * @param childrenPrefix
 */
void show(AVLNODE *p, string prefix, string childrenPrefix)
{
    if (p == NULL)
    {
        return;
    }
    char s[100];
    traverse2(p->list, s);
    printf("%s%.2lf: %s\n", prefix.c_str(), p->score, s);
    if (p->left == NULL)
    {
        show(p->right, childrenPrefix + "R-- ", childrenPrefix + "    ");
        return;
    }
    show(p->right, childrenPrefix + "R-- ", childrenPrefix + "|   ");
    show(p->left, childrenPrefix + "L-- ", childrenPrefix + "    ");
}

/**
 * @brief In AVLT
 *
 * @param tree
 */
void show(AVLTREE tree)
{
    show(tree.root, "", "");
    printf("\n");
}

/**
 * @brief Tạo AVLT từ array a[]
 *
 * @param p
 * @param a
 * @param n
 */
void generate_AVLT(AVLTREE &tree, STUDENT students[], int n)
{
    initialize(tree);

    for (int i = 0; i < n; i++)
    {
        insert_node(tree.root, students[i]);
    }
}

/**
 * @brief Tìm kiếm node chứa giá trị id
 *
 * @param p
 * @param x
 * @return AVLNODE*
 */
NODE *search(AVLNODE *p, STUDENT student)
{
    if (p == NULL)
        // không tìm thấy
        return NULL;
    if (p->score == student.score)
        // tìm student trong p->list
        return search(p->list, student.id);
    if (p->score > student.score)
        // tìm tiếp ở nhánh con trái
        return search(p->left, student);
    if (p->score < student.score)
        // tìm tiếp ở nhánh con phải
        return search(p->right, student);
    return NULL;
}

/**
 * @brief Tìm kiếm node chứa giá trị x trên AVLT 
 * 
 * @param tree 
 * @param x 
 * @return AVLNODE* 
 */
NODE *search(AVLTREE tree, STUDENT student)
{
    return search(tree.root, student);
}

/**
 * @brief Lặp lại c n lần và lưu kết quả vào s
 * 
 * @param s 
 * @param c 
 * @param n 
 */
void repeat(char *s, char c, int n){
    strcpy(s,"");
    for (int i = 0; i < n; i++)
    {
        sprintf(s, "%s%c", s, c);
    }
}

/**
 * @brief Duyệt AVLT gốc p theo phương pháp LNR
 *
 * @param p
 */
void LNR(AVLNODE *p)
{
    if (p != NULL)
    {
        LNR(p->left);
        traverse(p->list);
        LNR(p->right);
    }
}

/**
 * @brief Duyệt AVLT theo phương pháp LNR
 * 
 * @param tree 
 */
void LNR(AVLTREE tree)
{
    char line[100];
    repeat(line, '-', 62+6+4);

    printf("STUDENT LIST\n");
    printf("%s\n", line);
    printf("| %6s | %-50s | %6s |\n", "ID", "Name", "Score");
    printf("%s\n", line);
    LNR(tree.root);
    printf("%s\n", line);
    printf("\n");
}

/**
 * @brief Duyệt AVLT gốc p theo phương pháp RNL
 *
 * @param p
 */
void RNL(AVLNODE *p)
{
    if (p != NULL)
    {
        RNL(p->right);
        traverse(p->list);        
        RNL(p->left);
    }
}

/**
 * @brief Duyệt AVLT theo phương pháp RNL
 * 
 * @param tree 
 */
void RNL(AVLTREE tree)
{
    char line[100];
    repeat(line, '-', 62+6+4);

    printf("STUDENT LIST\n");
    printf("%s\n", line);
    printf("| %6s | %-50s | %6s |\n", "ID", "Name", "Score");
    printf("%s\n", line);
    RNL(tree.root);
    printf("%s\n", line);
    printf("\n");
}