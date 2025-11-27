
#include <stdio.h>

int main(){
	//bien a chua dia chi cua phan tu dau tien a[0]
	int a[] = {1,5,3,9,8};
	int size = sizeof(a)/sizeof(a[0]);
	for(int i=0;i<size;i++){
		printf("%d\n",a[i]);
	}
}
1