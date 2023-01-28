#include <stdio.h>
#include <string.h>

struct number {
	int num ;
	struct number *next ;

} ;

//------------------------------------------------------------------------------------------------

void ShowAll( struct number *walk ) ;

void ShowBack( struct number *walk );

void Swap( struct number **walk, int numfirst, int numsecond );

struct number *AddNode( struct number **walk, int Numdata ) ;

//------------------------------------------------------------------------------------------------

int main() {
	struct number *start, *now ;
	int i ; start = NULL ;
	
//addnode
	AddNode( &start, 10 );
	AddNode( &start, 20 );
	AddNode( &start, 30 );
	AddNode( &start, 40 );
//input value the you want.
	ShowAll(start);
	int youneed, tochange, stop;
		while(stop != 1){
			
			printf( "^select the desired number^\n" );
        	printf("-> ");
        	
	        	scanf( "%d", &youneed );
	        	
	    	printf( "Enter the number you want to change\n" );
	        printf("-> ");
	        
	        	scanf( "%d", &tochange );
		    	Swap(&start, youneed, tochange);
		    	
		    ShowAll(start); //10, 30, 20, 40
			printf("\n-----------------------------------------\n");
			printf( "want stop = 1\n" );
			printf("-> ");
			
				scanf( "%d", &stop );
				
			printf("-----------------------------------------\n\n");
			ShowAll( start );
		}
            
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

void Swap( struct number **walk, int numfirst, int numsecond ){
	
	while( *walk != NULL ) {
		
		if( (*walk)->num == numfirst ){
			
			(*walk)->num = numsecond ;
			
		}else if( (*walk)->num == numsecond ){
			
			(*walk)->num = numfirst ;
			
		}//end if (*walk)->num == numNow
		
		walk = &(*walk)->next;
		
	}//end while walk
	
}//end function
