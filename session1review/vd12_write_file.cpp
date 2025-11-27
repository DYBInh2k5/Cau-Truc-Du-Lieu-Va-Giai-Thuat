
Memo
Highlight
#include <stdio.h>

int main(){
	char c;
	const int CTRL_Z = -1;
	FILE *f = fopen("vd.txt","w");
	//Vong lap vo tan
	while(1){
		c = getchar();
		if(c==CTRL_Z) break;
		fputc(c,f);
	}
	fclose(f);
}


1