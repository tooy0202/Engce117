#include <stdio.h>
#include <string.h>

char *Gtext();

int main(){
	char str[20];					//value size input string text
	strcpy( str, Gtext() );			//copy value Gtext to str
	printf("\n%s\n", str);
	return 0;
}

char *Gtext(){
	char *text = new char[20];		//create *text get string value
	gets(text);
	return text;
}

