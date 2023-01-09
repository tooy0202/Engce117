#include <stdio.h>
#include <string.h>

struct studentNode {
	char name[20] ;
	int age ;
	char sex ;
	float gpa ;
	struct studentNode *next ;
} ;

void GoNext( struct studentNode ***walk );
void ShowAll( struct studentNode **walk );
void DelNode( struct studentNode **walk);
void InsNode( struct studentNode **nowNode, char n[], int a, char s, float g );

int main() {
	struct studentNode *start, **now ;
	start = NULL ; now = &start ;
	InsNode( now, "one", 6, 'M', 3.11 ) ; 
	ShowAll( &start ) ;
	InsNode( now, "two", 8, 'F', 3.22 ) ; 
	ShowAll( &start ) ;
	//---
	GoNext( &now ) ;
	//---
	InsNode( now, "three", 10, 'M', 3.33 ) ; 
	ShowAll( &start ) ;
	InsNode( now, "four", 12, 'F', 3.44 ) ; 
	ShowAll( &start ) ;
	//---
	GoNext( &now ) ;
	//--
	DelNode( now ) ; 
	ShowAll( &start ) ;
	return 0 ;
}//end function

void ShowAll( struct studentNode **walk ) {
	while( *walk != NULL ) {
		printf( "%s ", (*walk)->name ) ;
		walk = &(*walk)->next ;
	}//end while
	printf( "\n" ) ;
}//end function

void InsNode( struct studentNode **nowNode, char n[], int a, char s, float g ){
    struct studentNode *newNode = new studentNode;
	strcpy( newNode->name, n ) ;
	newNode->age = a ;
	newNode->sex = s ;
	newNode->gpa = g ;
	newNode->next = NULL;
    if ( *nowNode == NULL ){
        *nowNode = newNode;
    }
    else {
        newNode->next = *nowNode;
        *nowNode = newNode;
    }
}//end void InsNode struct studentNode **New function

void DelNode( struct studentNode **walk) {
	struct studentNode *temp;
	temp = (*walk)->next;
	(*walk)->next = temp;
}//end void InsNode function

void GoNext( struct studentNode ***walk ) {
	**walk = (*(*walk))->next;
} //end function

