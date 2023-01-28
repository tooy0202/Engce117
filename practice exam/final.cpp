//---------------------------- athit suntalodom 65543206086-2 Sec.3------------------------------------
//---------------------------- https://youtu.be/3Ccr3p-K0Y4 -------------------------------------------
#include <stdio.h>
#include <string.h>

struct number {
	int num ;
	struct number *next ;

} ;

//--Prototype function----------------------------------------------------------------------------

void ShowAll( struct number *walk ) ;

void ShowBack( struct number *walk ) ;

void Update( struct number **walk, int numNow, int numUp) ;

void Swap( struct number **walk, int numfirst, int numsecond ) ;

struct number *AddNode( struct number **walk, int Numdata ) ;

//--start main--------------------------------------------------------------------------------------

int main() {
	struct number *start ;
	int i, youneed, tochange, stop ; start = NULL ;
	
//addnode
	AddNode( &start, 10 );
	AddNode( &start, 20 );
	AddNode( &start, 30 );
	AddNode( &start, 40 );
	
//Select the desired topic
	printf("1.Update : 2.Showback : 3.Swap\n");
	printf("-> ");
	scanf("%d", &i);
	printf("\n--------------------------------\n\n");
	ShowAll(start);
	
	//start program
	switch ( i ) {
		//start funtion Update
        case 1:
        	while( stop != 1 ){
        		printf( " 1 )Select the desired number.\n" );
        		printf("-> ");
        		
	        		scanf( "%d", &youneed );
	        		
	        	printf( " 2 )Enter the number you want to change.\n" );
	        	printf("-> ");
	        	
	        		scanf( "%d", &tochange );
			    	Update( &start, youneed, tochange );
			    	
			    ShowAll( start ); //99, 20, 30, 40
			    printf("\n--------------------------------\n");
				printf( "Want stop Enter(1).\n" );
			    printf("-> ");
			    
			    	scanf( "%d", &stop );
			    
			    if(stop != 1){
			    	printf("--------------------------------\n\n");
			    	ShowAll( start );	
				}
			}
            break;
            //end funtion Update
            
        //start funtion showback
        case 2:
		    ShowBack(start); //40, 30, 20, 10
            break;
        //end funtion showback
        
        
        //start funtion Swap
        case 3:
			while(stop != 1){
				
				printf( " 1 )Select number you want to swap.\n" );
	        	printf("-> ");
	        	
		        	scanf( "%d", &youneed );
		        	
		    	printf( " 2 )Select number you want to swap.\n" );
		        printf("-> ");
		        
		        	scanf( "%d", &tochange );
			    	Swap(&start, youneed, tochange);
			    	
			    ShowAll(start);
				printf("\n--------------------------------\n");
				printf( "Want stop Enter(1).\n" );
				printf("-> ");
				
					scanf( "%d", &stop );
					
			    if(stop != 1){
			    	printf("--------------------------------\n\n");
			    	ShowAll( start );	
				}
			}
            break;
            //end funtion Swap
            
        default:
            printf(" ");
            
    }//end program
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
			break;
			
		}//end if (*walk)->num == numNow
		
		walk = &(*walk)->next;
		
	}//end while walk

}//end void Update function

//------------------------------------------------------------------------------------------------

void ShowBack( struct number *walk ){
	
	struct number *slide, *select;
	slide = select = NULL;
	
	while( walk != NULL ) {
		
        select = walk->next;
       
        walk->next = slide;
        
    	slide = walk;
    	
    	walk = select;

	}//end while change position
	
	walk = slide ;

    while( walk != NULL ) {
		printf( "%d ", walk->num ) ;
		walk = walk->next ;
		
	}//end while ShowBack
	printf( "\n" ) ;
	
}//end function


//------------------------------------------------------------------------------------------------


void Swap( struct number **walk, int numfirst, int numsecond ){
	
	while( *walk != NULL ) {
		
		if( (*walk)->num == numfirst ){
			
			(*walk)->num = numsecond ;
			
		}else if( (*walk)->num == numsecond ){
		
			(*walk)->num = numfirst ;
		}//end if find value 1 and value 2
		walk = &(*walk)->next;
		
	}//end while walk
	
}//end function


//------------------------------------------------------------------------------------------------
