#include<stdio.h>
#include<string.h>

struct name{											//------------------------struct name------------------------//
	char name[20];
	char namerich[20];
	int age;
	int money;
	int moneyR;
	char sex;
};

void find( struct name body[], int count ); 			//-----------------------void find-----------------------------//

void find( struct name body[], int count ){   			//-----------------------start void find-----------------------//
	int maxmoney, numberI;
	maxmoney = body[0].money;
	numberI = 0;
	for( int i = 1 ; i < count ; i++){
		if( body[i].money > maxmoney ){
			maxmoney = body[i].money;
			numberI = i;
			strcpy(body->namerich, body[numberI].name);	//-----------------------Input namerich-----------------------//
			body->moneyR = body[numberI].money;			//-----------------------Input money of namerich -------------//
		}
	}
}														//-----------------------End void find------------------------//

int main(){												//-----------------------start int main-----------------------//
	struct name ch[3];
	for( int i = 0 ; i < 2 ; i++){
		printf("Input name age sex money %d time\n", i+1);
		scanf("%s %d %c %d", ch[i].name, &ch[i].age, &ch[i].sex, &ch[i].money);//-----------------------Input data----//
	}
	find( ch, 2 );										//---------------send struct ch & 2 value to void find--------//
	printf("\n%s are the richest person with %d \n", ch->namerich, ch->moneyR);
	return 0;
}														//-----------------------stop int main-----------------------//


