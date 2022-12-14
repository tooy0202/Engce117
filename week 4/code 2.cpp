#include <stdio.h>
#include <string.h>
void GetText( char *text );
int main()
{
    char str[20];						//value size input string text
    GetText(str);						//str = text in funter Gettext
    printf( "\n%s\n", str );
    return 0;
}
void GetText( char *text ){
    strcpy(text, "hello hahahahah");	//copy hello hahahahah to text
}


