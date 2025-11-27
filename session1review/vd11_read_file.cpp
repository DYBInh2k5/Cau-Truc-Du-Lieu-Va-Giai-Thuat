
#include <stdio.h>

void read_file(char filename[]){
    //Mo text file de doc
	FILE *f = fopen(filename,"r");
	
	//Doc chuoi ky tu vao file
	char buf[100];
	while(fgets(buf,100,f) != NULL){
		printf("%s",buf);
	}
	
	//Dong file
	fclose(f);
}

int main(){
    char filename[]="vd.txt";
    read_file(filename);
    return 0;
}
1