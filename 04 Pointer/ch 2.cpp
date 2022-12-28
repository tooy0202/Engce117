#include <stdio.h>

void go( int ***p, int **z ) ;

void go( int ***p, int **z ) {//stat function
	*p = z;
	printf( "%d %p %p %p \n", ***p, **p, *p, p);
}//end function

int main() {
 int *b = new int ; *b = 10 ;
 int *c = new int ; *c = 20 ;
 int **a ;
 go( &a, &b ) ;
 printf( "%d %p %p %p \n", **a, *a, a, &a ) ;
 go( &a, &c ) ;
 printf( "%d %p %p %p \n", **a, *a, a, &a ) ;
 return 0 ;
}//end function
