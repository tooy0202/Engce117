#include<stdio.h>
#include<string.h>

struct name{
	char fname[20];
	char sex;
	int age;
};

typedef struct name n;
void switchvalue(struct name **Input, struct name lise[]);			//---------------------- void find -----------------//

void switchvalue(struct name **Input, struct name lise[]){			//------------------ start void switchvalue --------//
	*Input = lise;
}																	//-------------------- End void switchvalue --------//

int main(){
	struct name *goInput;
	goInput = new struct name[1];
	
	struct name ch[1];
	for( int i = 0 ; i < 1 ; i++){									//-------------------- start loopInput ------------//
		printf("Input Name time %d \n", i);
		scanf("%s %d %c", ch[i].fname, &ch[i].age, &ch[i].sex);
	}																//-------------------- End ------------------------//
	
	switchvalue(&goInput ,ch);
	printf("\nname is %s %d %c", goInput->fname, goInput->age, goInput->sex);
	return 0;
}
