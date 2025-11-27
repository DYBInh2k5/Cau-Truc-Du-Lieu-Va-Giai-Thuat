
#include <stdio.h>

int main(){
	//bien a chua dia chi cua phan tu dau tien a[0]
	int a[] = {1,5,3,9,8};
    int* p=a;
	int size = sizeof(a)/sizeof(a[0]);
	for(int i=0;i<size;i++){
		printf("%d\n",a[i]);
	}
    //truy cap a thong qua p
    for(int i=0;i<size;i++){
		printf("%d\n",*p);
        p++;
	}
    //in dia chi cua array a
    printf("Address of a: %u\n",a);
    printf("Address of a: %u\n",p);
    //in dia chi cua a[3]
    p = a;
    printf("Address of a[3]: %u\n",&a[3]);
    printf("Address of a[3]: %u\n",(p+3));
}
1