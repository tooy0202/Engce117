#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
 char name[ 20 ] ;
 int age ;
 char sex ;
 float gpa ;
 struct studentNode *next ;
} ;

class LinkedList {
 protected :
  struct studentNode *start, **now ;
 public :
  LinkedList() ;
  ~LinkedList() ;
  void InsNode( char n[], int a, char s, float g ) ;
  void DelNode() ;
  void GoNext() ;
  void GoFirst() ;
  void GoLast() ;
  void ShowAll() ;
  int FindNode( char n[] ) ;
  struct studentNode *NowNode() ;
  void EditNode( char n[], int a, char s, float g ) ;
} ; //end class

void EditData( LinkedList *ll ) ;
void AddData( LinkedList *ll ) ;
void FindData( LinkedList *ll ) ;
void readfile( LinkedList *ll ) ;
void writefile( LinkedList *ll ) ;

int main() {
	 LinkedList listA ;
	 NewList listB ;
	 LinkedList *listC ;
	
	 listA.InsNode( "one", 1, 'A', 1.1 ) ;
	 listA.InsNode( "two", 2, 'B', 2.2 ) ;
	 listA.InsNode( "three", 3, 'C', 3.3 ) ;
	 listA.GoNext() ;
	 listA.ShowNode() ;
	
	 listB.InsertNode( "four", 4, 'D', 4.4 ) ;
	 listB.InsertNode( "five", 5, 'E', 5.5 ) ;
	 listB.InsertNode( "six", 6, 'F', 6.6 ) ;
	 listB.GoNext() ;
	 listB.DelNode() ;
	 listB.ShowNode() ;
	
	 listC = &listA;
	 listC->GoNext() ;
	 listC->ShowNode() ;
	
	 listC = &listB ;
	 listC->ShowNode() ;
	
	 return 0 ;
}//end function

void readfile( LinkedList *ll ){
	char n[20];
	int a,i;
	char s;
	float g;
	FILE *fp;
	fp = fopen( "C:/student.dat", "r" );
	if( fp == NULL ) {
		printf( "Can't open file!\n" );
		exit( 0 );
	}//end if
	for( i = 0; i < 2; i++ ){
		fscanf( fp, "%s %d %c %f", &n, &a, &s, &g );
		ll->InsNode( n, a, s, g );
	}//end for
	fclose( fp );	
}//end function readfile

void writefile( LinkedList *ll ){
	char n[20];
	int a,i;
	char s;
	float g;
	FILE *fp;
	fp = fopen( "C:/student.dat", "w" );
	if( fp == NULL ) {
		printf( "Can't open file!\n" );
		exit( 0 );
	}//end if
	ll->GoFirst();
	while( ll->NowNode() != NULL ){
		struct studentNode *nodehere = ll->NowNode();
		fprintf( fp, "%s %c %d %.2f", nodehere->name, nodehere->sex, nodehere->age, nodehere->gpa );
		ll->GoNext();
	}//end while
	fclose( fp );
}//end function writefile

void AddData( LinkedList *ll ){
    char name[20];
    int age;
    char sex;
    float gpa;
    printf( "Enter your name: " );
 	scanf( "%s", name );
 	printf( "Enter your age: " );
 	scanf( "%d", &age );
 	printf( "Enter your sex: " );
 	scanf( " %c", &sex );
 	printf( "Enter your gpa: " );
 	scanf( "%f", &gpa );
 	ll->InsNode( name, age, sex, gpa );
}//end function AddData

void EditData( LinkedList *ll ){
	char name[ 20 ];
    int age;
    char sex;
    float gpa;
    printf( "Enter name to edit: " );
	scanf( "%s", &name );
    if( ll->FindNode( name ) == 1 ){
		printf( "Edit :: \n " );
    	printf(  "Enter your name: " );
 		scanf( "%s", name );
 		printf( "Enter your age: " );
 		scanf( "%d", &age );
 		printf( "Enter your sex: " );
 		scanf( " %c", &sex );
 		printf( "Enter your gpa: " );
 		scanf( "%f", &gpa );
 		ll->EditNode( name, age, sex, gpa );
	}else{
		printf( "Not have name is %n \n",name );
	}//end if
	//ll->ShowAll();
}//end function EditData

void FindData( LinkedList *ll ){
	char name[ 20 ];
    int age;
    char sex;
    float gpa;
    printf(  "Enter name to find: " );
	scanf(  "%s", &name );
	if( ll->FindNode( name ) == 1 ){
		struct studentNode *shownode = ll->NowNode();
		printf( "Name: %s\n", shownode->name );
		printf( "Age: %d\n", shownode->age );
		printf( "Sex: %c\n", shownode->sex );
		printf( "GPA: %.2f\n", shownode->gpa );
		printf( "\n" );
	}else{
		printf( "Not have name is %n  \n",name );
	}//end if
}//end function FindData

///////////////////////////////////////////////////////////////////////////////
LinkedList :: LinkedList() {
  start = NULL;
  now = &start;
}//end function LinkedList

LinkedList :: ~LinkedList() {
	struct studentNode *temp = *now;
	while (  temp != NULL ) {
		start = start->next;
    delete temp;
    temp = start;
  }//end while
}//end function ~LinkedList

void LinkedList :: InsNode(  char n[], int a, char s, float g ) {
	struct studentNode *newNode = new studentNode;
	strcpy(  newNode->name, n );
	newNode->age = a;
	newNode->sex = s;
	newNode->gpa = g;
	newNode->next = *now;
	*now = newNode;
}//end function InsNode

void LinkedList :: DelNode() {
	struct studentNode *temp = *now ;
	*now = ( *now )->next ;
	delete temp ;
	printf( "Delete node succeed" );
}//end function DelNode

void LinkedList::GoNext() {
	if(  *now != NULL ){
 		*now = ( **now ).next ;
 	}//end if
}//end function GoNext

void LinkedList :: GoFirst() {
	now = &start;
}//end function GoFirst

void LinkedList :: GoLast() {
	GoFirst();
	while ( *now != NULL ){
  		*now = ( **now ).next ;
	}//end while
}//end function GoLast

struct studentNode *LinkedList::NowNode() {
	return *now ;
}//end function NowNode

int LinkedList::FindNode( char n[] ) {
	int count = 0;
	GoFirst();
	while ( *now != NULL ) {
		if ( strcmp( ( **now ).name, n ) == 0 ){
   			count++;
   			*now = NowNode();
  		}//end if
		return count;
		GoNext();
	}//end while
 	return -10;
}//end function FindNode

void LinkedList::EditNode( char n[], int a, char s, float g ) {
	int pos = FindNode( n );
	if ( pos == -10 ) {
		printf( "Not have node to edit\n" );
		return;
	}//end if
	struct studentNode *temp = NowNode();
	strcpy( temp->name, n );
	temp->age = a;
	temp->sex = s;
	temp->gpa = g;
}//end function EditNode

void LinkedList::ShowAll() {
	GoFirst();
	while ( *now != NULL ) {
		printf( "Name: %s\n", ( *now )->name );
		printf( "Age: %d\n", ( *now )->age );
		printf( "Sex: %c\n", ( *now )->sex );
		printf( "GPA: %.2f\n", ( *now )->gpa );
		printf( "\n" );
		GoNext();
	}//end while
}//end function ShowAll

