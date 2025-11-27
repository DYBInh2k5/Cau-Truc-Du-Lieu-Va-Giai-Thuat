#include <stdio.h>
#include <stdlib.h>

//int main(int argc, char* argv[]){
int main(int argc, char** argv){		
    int s = 0;
	for(int i=1; i<argc; i++){
		s += atoi(argv[i]);
	}
    printf("Sum: %d\n", s);
}