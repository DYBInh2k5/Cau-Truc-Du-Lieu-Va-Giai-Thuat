#include "avltree.h"

int main()
{
    AVLTREE avlt;
    DATA a[] = {1, 7, 9, 18, 25, 30, 39, 42, 43, 48, 52, 65, 69, 70, 72, 86, 95, 100};
    int n = sizeof(a)/sizeof(DATA);
    generate_AVLT(avlt, a, n);
    show(avlt);

    insert_node(avlt.root, 80);
    show(avlt);
    
    //Giải phóng bộ nhớ chứa AVLT
    delete_tree(avlt);
    return 0;
}