
#include <stdio.h>
#include <iostream>
using namespace std;

#define LH -1 // cây con trái cao hơn
#define EH 0  // hai cây con bằng nhau
#define RH 1  // cây con phải cao hơn

#define DATA int

typedef struct AVLNODE
{
    DATA info;
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


AVLNODE *create_node(DATA data)
{
    AVLNODE *p = new AVLNODE;
    if (p != NULL)
    {
        p->info = data;
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
int insert_node(AVLNODE *&p, DATA x)
{
    int res;
    // nếu cây rỗng
    if (p == NULL)
    {
        p = create_node(x);
        if (p == NULL)
        {
            return -1; // thêm không thành công do thiếu bộ nhớ
        }
        return 2; // thêm thành công và làm tăng chiều cao cây
    }
    else // nếu cây khác rỗng
    {
        if (p->info == x)
        {
            return 0; // x đã tồn tại trong cây
        }
        else if (p->info > x)
        {
            res = insert_node(p->left, x);
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
        else // p->info < x
        {
            res = insert_node(p->right, x);
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
    printf("%s%d\n", prefix.c_str(), p->info);
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
 * @brief Tạo AVLT với n node chứa các giá trị ngẫu nhiên thuộc [min, max]
 *
 * @param p
 * @param n
 * @param min
 * @param max
 */
void generate_AVLT(AVLTREE &tree, int n, int min, int max)
{
    initialize(tree);

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        insert_node(tree.root, rand() % (max - min + 1) + min);
    }
}

/**
 * @brief Tạo AVLT từ array a[]
 *
 * @param p
 * @param a
 * @param n
 */
void generate_AVLT(AVLTREE &tree, DATA a[], int n)
{
    initialize(tree);

    for (int i = 0; i < n; i++)
    {
        insert_node(tree.root, a[i]);
    }
}

/**
 * @brief Tìm kiếm node chứa giá trị x
 *
 * @param p
 * @param x
 * @return AVLNODE*
 */
AVLNODE *search(AVLNODE *p, DATA x)
{
    if (p == NULL)
        // không tìm thấy
        return NULL;
    if (p->info == x)
        // tìm thấy p
        return p;
    if (p->info > x)
        // tìm tiếp ở nhánh con trái
        return search(p->left, x);
    if (p->info < x)
        // tìm tiếp ở nhánh con phải
        return search(p->right, x);
    return NULL;
}

/**
 * @brief Tìm kiếm node chứa giá trị x trên AVLT 
 * 
 * @param tree 
 * @param x 
 * @return AVLNODE* 
 */
AVLNODE *search(AVLTREE tree, DATA x)
{
    return search(tree.root, x);
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
        printf("%d ", p->info);
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
    LNR(tree.root);
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
        printf("%d ", p->info);
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
    RNL(tree.root);
    printf("\n");
}