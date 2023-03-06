#include <stdio.h>
#include <string.h>

struct studentNode {
 char name[ 20 ] ;
 int age ;
 char sex ;
 float gpa ;
 struct studentNode *next ;
} ;

class LinkedList{
 	protected :
  		struct studentNode *start, **now ;
 	public :
  		LinkedList(); 
  		~LinkedList();
  		void InsNode( char n[], int a, char s, float g ); 
  		void DelNode(); 
  		GoNext(); 
  		virtual void ShowNode() ;
} ; // End class

class NewList : public LinkedList {
 	public :
  		GoFirst() ; 
  		virtual void ShowNode() ;
} ; // End class


int main() {
 LinkedList listA ;
 NewList listB ;
 LinkedList *listC ;

 listA.InsNode( "one", 1, 'A', 1.1 );
 listA.InsNode( "two", 2, 'B', 2.2 );
 listA.InsNode( "three", 3, 'C', 3.3 );
 listA.GoNext() ;
 listA.ShowNode() ;

 listB.InsNode( "four", 4, 'D', 4.4 ) ;
 listB.InsNode( "five", 5, 'E', 5.5 ) ;
 listB.InsNode( "six", 6, 'F', 6.6 ) ;
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

LinkedList :: LinkedList() {
  start = NULL;
  now = &start;
}//end function LinkedList

LinkedList :: ~LinkedList() {
  struct studentNode *temp = *now;
  while ( temp != NULL ) {
    start = start->next;
    delete temp;
    temp = start;
  }//end while
}//end function ~LinkedList

void LinkedList :: InsNode( char n[], int a, char s, float g ) {
  struct studentNode *newNode = new studentNode;
  strcpy( newNode->name, n );
  newNode->age = a;
  newNode->sex = s;
  newNode->gpa = g;
  newNode->next = *now;
  *now = newNode;
}//end function InsNode

void LinkedList :: DelNode() {
  struct studentNode *temp = *now ;
  *now = (*now)->next ;
  delete temp ;
}//end function DelNode

LinkedList :: GoNext() {
  *now = (*now)->next;
}//end function GoNext

NewList :: GoFirst() {
  now = &start ;
}//end function GoFirst

void LinkedList :: ShowNode(){
    printf( "%s", (*now)->name );
    printf( " %d", (*now)->age );
    printf( " %c", (*now)->sex );
    printf( " %.2f\n", (*now)->gpa );
    
}//end function ShowNode

void NewList::ShowNode(){
    while(*now != NULL){
        printf( "Name: %s\n", (*now)->name );
        printf( "Age: %d\n", (*now)->age );
        printf( "Sex: %c\n", (*now)->sex );
        printf( "GPA: %.1f\n", (*now)->gpa );
        GoNext();
    }//end while
}//end function ShowNode

