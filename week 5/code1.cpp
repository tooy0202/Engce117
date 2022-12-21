#include<stdio.h>
#include<string.h>

struct name{									//------------------------struct------------------------//
	char fname[20];					
	char lname[20];					
	char sex[5];
	int age;
};

typedef struct name n;

int main(){
	struct name fpeople;						//------------nickname struct name----------------------//
	n speople;									//------------nickname struct name----------------------//
	strcpy(fpeople.fname, "Tony");
	strcpy(speople.fname, "Sara");
	fpeople.age = 18;
	speople.age = 20;
	strcpy(fpeople.sex, "Man" );
	strcpy(speople.sex, "girl");
	printf("%s %d %s\n", fpeople.fname, fpeople.age,fpeople.sex );
	printf("%s %d %s\n", speople.fname, speople.age,speople.sex );
	return 0;
}

