#include <stdio.h>
#include <string.h>

struct studentNode {
	char name[ 20 ] ;
	int age ;
	char sex ;
	float gpa ;
	struct studentNode *next ;
	struct studentNode *back ;
} ;


//-----------------------------------------------------------------------------------------------------------------------------


void ShowAll( struct studentNode *walk ) ;
void ShowBack( struct studentNode *walk ) ;
struct studentNode *AddNode( struct studentNode **walk, char n[], int a, char s, float g  ) ;
void InsNode( struct studentNode *walk, char n[], int a, char s, float g) ;
void DelNode( struct studentNode **walk) ;
void GoBack( struct studentNode **walk ) ;


//-----------------------------------------------------------------------------------------------------------------------------


int main() {
	struct studentNode *start, *now, *last ;
	start = NULL ;
	now = AddNode( &start, "one", 6, 'M', 3.11 ) ; ShowAll( start ) ;
	now = AddNode( &start, "two", 8, 'F', 3.22 ) ; ShowAll( start ) ;
	InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( start ) ;
	InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( start ) ; 
	last = now;
	ShowBack( last ) ;
	GoBack( &now ) ;
	DelNode( &now ) ; ShowAll( start ) ;
	DelNode( &now ) ; ShowAll( start ) ;
	DelNode( &now ) ; ShowAll( start ) ;
	return 0 ;
}//end main


//-----------------------------------------------------------------------------------------------------------------------------


struct studentNode *AddNode( struct studentNode **walk, char n[], int a, char s, float g  ) {
	
	struct studentNode *temp = NULL;
	
	while( *walk != NULL){
		temp = *walk;
		walk = &(*walk)->next;
	}
	
	*walk = new struct studentNode;
	strcpy( (*walk)->name, n ) ;
	(*walk)->age = a ;
	(*walk)->sex = s ;
	(*walk)->gpa = g ;
	(*walk)->next = NULL;
	(*walk)->back = temp;
	return *walk;
}


//-----------------------------------------------------------------------------------------------------------------------------


void InsNode( struct studentNode *walk, char n[], int a, char s, float g ){
	struct studentNode **begin;
	if( walk->back != NULL ){
		walk->back->next = new struct studentNode;
		strcpy( walk->back->next->name, n ) ;
		walk->back->next->age = a;
		walk->back->next->sex = s;
		walk->back->next->gpa = g;
		walk->back->next->next = walk;
		walk->back->next->back = walk->back;
		walk->back = walk->back->next;
	}else{
		*begin = new struct studentNode;
		strcpy( (*begin)->name, n ) ;
		(*begin)->age = a;
		(*begin)->sex = s ;
		(*begin)->gpa = g ;
		(*begin)->next = walk;
		(*begin)->back = NULL;
		walk->back = *begin;
	}
}


//-----------------------------------------------------------------------------------------------------------------------------


void DelNode( struct studentNode **walk){
	struct studentNode *temp;
	
		(*walk)->back->next = (*walk)->next;
		
	if( (*walk)->next != NULL ){
		(*walk)->next->back = (*walk)->back;
		temp = (*walk)->next;
	}else{
		temp = (*walk)->back;
	}
	
	delete *walk;
	*walk = temp;
}


//-----------------------------------------------------------------------------------------------------------------------------


void GoBack( struct studentNode **walk ) {
	*walk = (*walk)->back;
} //end function


//-----------------------------------------------------------------------------------------------------------------------------


void ShowAll( struct studentNode *walk ) {
	while( walk != NULL ) {
		printf( "%s ", walk->name ) ;
		walk = walk->next ;
	}//end while
	printf("\n");
}//end function


//-----------------------------------------------------------------------------------------------------------------------------


void ShowBack( struct studentNode *walk ) {
	while( walk != NULL ) {
		printf( "%s ", walk->name ) ;
		walk = walk->back ;
	}//end while
	printf("\n");
}//end function
