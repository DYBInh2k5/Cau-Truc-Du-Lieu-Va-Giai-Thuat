
#include <stdio.h>

int main(){
	int n = 100;
	int* p = &n;
	//In gia tri cua bien n
	printf("%d\n",n);
	printf("%d\n",*p);
	//in dia chi cua bien n
	printf("%u\n",&n);
	printf("%u\n",p);
}
1