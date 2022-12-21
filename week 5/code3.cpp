#include<stdio.h>
#include<string.h>

struct name{										//------------------------struct name------------------------//
	char name[20];
	int age;
	char sex;
};

struct name find( struct name body[], int count );

struct name find( struct name body[], int count ){//-----------------------start void find-----------------------//
	int maxAge, maxI;
	maxAge = body[0].age;
	maxI = 0;
	for( int i = 1 ; i < count ; i++){				//-----------------------start for count maxAge--------------//
		if( body[i].age > maxAge ){
			maxAge = body[i].age;
			maxI = i;
		}
	}												//-----------------------End for count maxAge-----------------//
	return body[maxI];
}													//-----------------------End void find------------------------//

int main(){
	struct name ch[3];
	for( int i = 0 ; i < 3 ; i++){									//---------------    Input value loop   ------//
		printf("Input Name time %d \n", i);
		scanf("%s %d %c", ch[i].name, &ch[i].age, &ch[i].sex);
	}																//--------------------   End loop ------------//
	struct name chHige;
	chHige = find( ch, 3 );
	printf("the oldest person is %s age %d", chHige.name, chHige.age);
	return 0;
}


