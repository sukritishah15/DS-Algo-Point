// C program to search an element in row-wise and column-wise sorted matrix 
#include <stdio.h> 

#define MAX_SIZE 1000

int searchElement(int mat[MAX_SIZE][MAX_SIZE], int n, int m, int x)
{
	int i = 0, j = m-1;
	
	while ( i < n && j >= 0 )
	{
		if ( mat[i][j] == x ){
			//printf("\nThe Element Found at the position :  %d, %d", i, j);
			return 1;
		}
		if ( mat[i][j] < x )
			i++;			
		else
			j--; 

	}

	return 0;  
}

int main() 
{ 

	int n, m, mat[MAX_SIZE][MAX_SIZE], i, j, element;
	
	
	printf("Enter size of rows and columns :- ");
	scanf("%d%d", &n, &m);

	printf("\nEnter elements :- \n");
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			scanf("%d", &mat[i][j]);
		}
	}

	printf("\nEnter element to be searched :- ");
	scanf("%d", &element);

	
	if (searchElement(mat, n, m, element))
		printf("\nElement Found!");
	else
		printf("\nElement Not Found!");
	
	return 0; 
} 


/*
Problem: Find if an element x is present in a 2D matrix when matrix is sorted in increasing order both row and column wise.

Sample Input/Output:

1). 

Enter size of rows and columns :- 4 4 

Enter elements :- 
10 20 30 40
15 25 35 45
27 29 37 48
32 33 39 50

Enter element to be searched :- 33

Element Found!

2). 

Enter size of rows and columns :- 4 4 

Enter elements :- 
10 20 30 40
15 25 35 45
27 29 37 48
32 33 39 50

Enter element to be searched :- 34

Element Not Found!


Time Complexity  : O(m+n)
Space complexity : O(1)
*/