#include <stdio.h>
#include <string.h>

struct studentNode {
	char name[20] ;
	int age ;
	char sex ;
	float gpa ;
	struct studentNode *next ;
	struct studentNode *back ;
} ;

void ShowAll( struct studentNode *walk ) ;
void DelNode( struct studentNode *walk);
void InsNode( struct studentNode *walk, char n[], int a, char s, float g) ;
struct studentNode *AddNode( struct studentNode **walk, char n[], int a, char s, float g  ) ;


int main() {
	struct studentNode *start, *now ;
	start = NULL ;
	now = AddNode( &start, "one", 6, 'M', 3.11 ) ;
	ShowAll( start ) ;
	now = AddNode( &start, "two", 8, 'F', 3.22 ) ; 
	ShowAll( start ) ;
	//-----------------------------------------------------------------
	InsNode( now, "three", 10, 'M', 3.33 ) ; 
	ShowAll( start ) ;
	InsNode( now, "four", 12, 'F', 3.44 ) ; 
	ShowAll( start ) ;
	//-----------------------------------------------------------------
	DelNode( now ) ;
	ShowAll( start ) ;
	return 0 ;
}//end function

void ShowAll( struct studentNode *walk ) {
	while( walk != NULL ) {
		printf( "%s ", walk->name ) ;
		walk = walk->next ;
	}//end while
	printf( "\n" ) ;
}//end function

struct studentNode *AddNode( struct studentNode **walk, char n[], int a, char s, float g  ) {
	
    while(*walk != NULL){
		walk = &(*walk)->next;
    }//end while
	*walk = new struct studentNode;
    strcpy( (*walk)->name, n ) ;
	(*walk)->age = a ;
	(*walk)->sex = s ;
	(*walk)->gpa = g ;
	(*walk)->next = NULL ;
	
	return *walk;
}//end struct studentNode *AddNode function

void InsNode( struct studentNode *walk, char n[], int a, char s, float g) {
	struct studentNode *temp;
	temp = walk->next;
	walk->next = new struct studentNode;
	strcpy( walk->next->name, n ) ;
	walk->next->age = a ;
	walk->next->sex = s ;
	walk->next->gpa = g ;
	walk->next->next = temp;
}//end void InsNode function

void DelNode( struct studentNode *walk) {
	struct studentNode *temp;
	walk->next = walk->next->next;
	temp = walk->next;
	walk = temp;
}//end void InsNode function


