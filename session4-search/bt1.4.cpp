/*
1.4. Viết hàm find_char(…) tìm kiếm một ký tự trong một chuỗi ký tự. 
Nếu tìm thấy, trả về vị trí đầu tiên của ký tự trong chuỗi, nếu không, trả về -1.
*/
#include <stdio.h>

//int find_char(char *s, char c)
int find_char(char s[], char c){
    for (int i = 0; s[i]!='\0'; i++)
    {
        if(s[i]==c){
            return i;
        }
    }
    return -1;
}

int main(){
    char s[]="Hom nay toi hoc cac giai thuat tim kiem";
    char c = 'o';
    
    int pos = find_char(s, c);
    printf("Character position: %d\n", pos);
    return 0;
}