/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int *ar( int *row, int *col) ;

int *ar( int *row, int *col){
    int *a;
    printf("Input\n");
    scanf("%d %d", row, col);
    a = new int[ *row * *col ];
    for(int i = 0; i < *row; i++){
        for(int j = 0; j < *row; j++){
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[ i * *col + j]);
        }
    }
    return a;
}

int main()
{
    int r, c, *arr;
    arr = ar( &r, &c );
    delete [] arr;
    return 0;
}

	printf("Please type the size of array: \n");
	scanf("%d",&size);
	char *str_array[size];
	char array_i[100];
	printf("Enter the  strings:\n");
	for(i=0;i<size;i++){
		scanf("%s", array_i);
		str_array[i]= (char*)malloc(strlen(array_i)*sizeof(char));
		strcpy(str_array[i],array_i);
	}
	printf("Your strings were:  \n");
		for(i=0;i<size;i++){
        printf("%s\n", str_array[i]);
    }
	
	strcpy( str, Gtext() );	
	printf( "\n%s\n", str );
