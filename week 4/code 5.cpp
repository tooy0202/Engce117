#include <string.h>
#include <stdio.h>
int size;

char *Gtext();

int main(){
	printf("Please type the size of array: \n");
	scanf("%d", &size);
	char *str;
	char *text[size];
	char *pointertoarray;					//value size input string text	//value size input string text//copy value Gtext to str
	for(int i = 0; i < size; i++ ){
		str = Gtext();
		printf("%s\n", &str);
	}
	return 0;
}

char *Gtext(){
	char (*text_array)[15];				//create *text get string value
	char *text = new char[15];
	scanf("%s",&text_array);
	return *text_array;
}

