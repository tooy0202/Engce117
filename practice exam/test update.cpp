#include <stdio.h>
#include <string.h>

struct studentNode {
	int num ;
	struct studentNode *next ;

} ;

//------------------------------------------------------------------------------------------------

void ShowAll( struct studentNode *walk ) ;

void Update( struct studentNode **walk, int numNow, int numUp);

struct studentNode *AddNode( struct studentNode **walk, int Numdata ) ;

//------------------------------------------------------------------------------------------------

int main() {
	struct studentNode *start, *now ;
	start = NULL ;
	AddNode( &start, 10 );
    AddNode( &start, 20 );
    AddNode( &start, 30 );
    AddNode( &start, 40 );
    ShowAll(start); //10, 20, 30, 40
    Update( &start, 10, 99 );
    ShowAll(start); //99, 20, 30, 40
    Update( &start, 10, 98 );
    ShowAll(start); //99, 20, 30, 40
	return 0 ;
}//end main


//------------------------------------------------------------------------------------------------


void ShowAll( struct studentNode *walk ) {
	
	while( walk != NULL ) {
		printf( "%d ", walk->num ) ;
		walk = walk->next ;
	}//end while ShowAll
	
	printf( "\n" ) ;
}//end function void ShowAll


//------------------------------------------------------------------------------------------------


struct studentNode *AddNode( struct studentNode **walk, int Numdata ) {
	
    while( *walk != NULL ){
		walk = &(*walk)->next;
    }//end while walk
	*walk = new struct studentNode;
	(*walk)->num = Numdata ;
	(*walk)->next = NULL ;
	
	return *walk;
}//end struct studentNode *AddNode function


//------------------------------------------------------------------------------------------------

void Update( struct studentNode **walk, int numNow, int numUp) {

	while( *walk != NULL ) {
		
		if( (*walk)->num == numNow ){
			
			(*walk)->num = numUp ;
			
		}//end if (*walk)->num == numNow
		
		walk = &(*walk)->next;
		
	}//end while walk

}//end void Update function


