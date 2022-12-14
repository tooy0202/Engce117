#include <stdio.h>
#include <string.h>
void GetText( char *text );
int main()
{
    char str[20];				//value size input string text
    GetText(str);				//str get value Gettext
    printf("\n%s\n", str);
    return 0;
}
void GetText( char *text ){
    gets(text);					//input string to text
}

