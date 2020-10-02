#include<stdio.h>
#define max(a,b) (a>b?a:b)

int currSum = 0, maxSum = 0;

int main(){

	int totalElements;
	printf("enter total size of the array\n");
	scanf("%d", &totalElements);

	int arr[totalElements];

	for(int i = 0; i < totalElements; i++){

		scanf("%d",&arr[i]);

	}

	for(int i = 0; i < totalElements; i++){

		currSum += arr[i];

		if(currSum < 0){

			currSum = 0;
		}

		maxSum = max(maxSum, currSum);
	}

	printf("Kadane's algorithm : max sum of contigous element : %d", maxSum);

}
/*
sample input 
enter total size of the array                                                                                                                
8                                                                                                                                            
-2 -3 4 -1 -2 1 5 -3 
sample output                                                                                                                        
7 

time and space complexity 
time complexity : O(n) 
space complexity : O(1)
*/
