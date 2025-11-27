#include "doubly-linked-list.h"

/**
 * @brief Xóa node sau p
 * 
 * @param list 
 * @param p 
 * @return true 
 * @return false 
 */
bool delete_after(DLIST &list, DNODE* p){

}

/**
 * @brief xóa node sau node chứa x
 * 
 * @param list 
 * @param x 
 * @return true 
 * @return false 
 */
bool delete_after(DLIST &list, DATA x){
    /*
    1. Tìm node chứa x (p trỏ vào node chứa x)
    2. Xóa node sau p
    */
    //1. Tìm node chứa x (p trỏ vào node chứa x)
    DNODE* p = search(list, x);
    if(p != NULL){
        //2. Xóa node sau p
        return delete_after(list, p);
    }
    return false;
}

int main(){

}