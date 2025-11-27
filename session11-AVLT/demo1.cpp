#include "avltree.h"

int main()
{
    AVLTREE avlt;
    generate_AVLT(avlt, 20, 1, 100);
    show(avlt);
    LNR(avlt);
    RNL(avlt);
    //Giải phóng bộ nhớ chứa AVLT
    delete_tree(avlt);
    return 0;
}

