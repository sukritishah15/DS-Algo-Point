//Given two strings find the longest common subsequence.

#include<stdio.h> 
#include<string.h>

int max(int a, int b); 

void lcs( char *X, char *Y, int m, int n ) 
{ 
	int L[m+1][n+1]; 
	int i, j, index; 

	for (i=0; i<=m; i++){ 
		for (j=0; j<=n; j++) { 
		
			if (i == 0 || j == 0) 
				L[i][j] = 0; 
			else if (X[i-1] == Y[j-1]) 
				L[i][j] = L[i-1][j-1] + 1; 
			else
			L[i][j] = max(L[i-1][j], L[i][j-1]); 
		} 
	} 

	index = L[m][n]; 
  
	char str[index+1]; 
	str[index] = '\0'; 

	i = m, j = n; 
	while (i > 0 && j > 0) {

		if (X[i-1] == Y[j-1]){ 
			str[index-1] = X[i-1]; 
			i--; j--; index--;     
		} 
		else if (L[i-1][j] > L[i][j-1]) 
			i--; 
		else
			j--; 
	} 

	printf("%s", str);

} 

int max(int a, int b) { 
	return (a > b)? a : b; 
} 

int main() 
{ 
	char X[] = "abaaba"; 
	char Y[] = "aababa"; 

	int m = strlen(X); 
	int n = strlen(Y); 

	lcs( X, Y, m, n ); 

	return 0; 
} 


/*
Problem Statement :- Given two strings find the longest common subsequence.

Sample Input/Output :- 

string1 : abaaba
string2: aababa
Output: aaba

Time Complexity :- O(n^2)
Space Complexity :- O(n^2)

*/