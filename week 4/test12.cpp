#include <stdio.h>
#include <string.h>
int size,i,s;
char *Gtext();
int Gar(int size);
int main(){
	printf("Please type the size of array: \n");
	scanf("%d",&size);
	char str[20];					//value size input string text
	strcpy( str, Gtext() );			//copy value Gtext to str
	printf("\n%s\n", str);
	return 0;
}

char *Gtext(){
	size = Gar();
	char *str_array = new char[size];		//create *text get string value
	
	gets(text);
	return text;
}

int Gar(int size){
	scanf("%d",size);
	return size;
}

