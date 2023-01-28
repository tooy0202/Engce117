#include <stdio.h>
#include <string.h>

struct number {
	int num ;
	struct number *next ;

} ;

//------------------------------------------------------------------------------------------------

void ShowAll( struct number *walk ) ;

void ShowBack2( struct number *walk );

void Update( struct number **walk, int numNow, int numUp);

struct number *AddNode( struct number **walk, int Numdata ) ;

//------------------------------------------------------------------------------------------------

int main() {
	struct number *start, *now ;
	start = NULL ;
    AddNode( &start, 10 );
    AddNode( &start, 20 );
    AddNode( &start, 30 );
    AddNode( &start, 40 );
    ShowAll(start); //10, 20, 30, 40
    ShowBack2(start); //40, 30, 20, 10
	return 0 ;
}//end main


//------------------------------------------------------------------------------------------------


void ShowAll( struct number *walk ) {
	
	while( walk != NULL ) {
		printf( "%d ", walk->num ) ;
		walk = walk->next ;
	}//end while ShowAll
	
	printf( "\n" ) ;
}//end function void ShowAll


//------------------------------------------------------------------------------------------------


struct number *AddNode( struct number **walk, int Numdata ) {
	
    while( *walk != NULL ){
		walk = &(*walk)->next;
    }//end while walk
	*walk = new struct number;
	(*walk)->num = Numdata ;
	(*walk)->next = NULL ;
	
	return *walk;
}//end struct studentNode *AddNode function


//------------------------------------------------------------------------------------------------

void Update( struct number **walk, int numNow, int numUp) {

	while( *walk != NULL ) {
		
		if( (*walk)->num == numNow ){
			
			(*walk)->num = numUp ;
			
		}//end if (*walk)->num == numNow
		
		walk = &(*walk)->next;
		
	}//end while walk

}//end void Update function

//------------------------------------------------------------------------------------------------

void ShowBack2( struct number *walk ){
	
	struct number *slide, *select;
	slide = select = NULL;
	
	while( walk != NULL ) {
		
        select = walk->next;
       
        walk->next = slide;
        
    	slide = walk;
    	
    	walk = select;

	}//end while ShowAll
	
	walk = slide ;

    while( walk != NULL ) {
		printf( "%d ", walk->num ) ;
		walk = walk->next ;
	}//end while ShowAll
	printf( "\n" ) ;
	
}//end function
