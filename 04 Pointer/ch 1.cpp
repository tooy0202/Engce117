#include <stdio.h>

void go( int **p, int *z ) ;

void go( int **p, int *z ) {//stat function
	*p = z;
	printf("%d %p %p\n", **p, *p, p);
}//end function

int main() {
	int *a, b = 10, c = 20 ;
	go( &a, &b ) ;
	printf( "%d %p %p\n", *a, a, &a ) ;
	printf( "-------------------\n" ) ;
	go( &a, &c ) ;
	printf( "%d %p %p\n", *a, a, &a ) ;
	return 0 ;
}//end function
