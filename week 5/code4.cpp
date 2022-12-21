#include<stdio.h>
#include<string.h>

struct name{
	char fname[20];
};

int main(){
	struct name *fpeople;						//-----------  create * struct ----------//				
	fpeople = new struct name[5];				//-----------  create struct site -------//	
	
	printf("Enter name \n");
    scanf("%s", fpeople->fname);
    
	printf("name is : %s\n", fpeople->fname);
	return 0;
}


