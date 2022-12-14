#include <stdio.h>
#include <string.h>

char *GetText();
int main()
{
    char *str;					//create *str get value GetText
    str = GetText();			//str = value retrun text
    printf( "\n%s\n", str );
    return 0;
}
char *GetText(){
    char *text = new char[15];	//create *text get string value
    gets(text);
    return text;
}



