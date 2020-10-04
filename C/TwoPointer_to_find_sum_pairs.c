#include<stdio.h>

void main() 
{
    printf("Enter size of array:");
	int n;
    scanf("%d", &n);
	int arr[n],i;
    printf("Enter sorted elements:");
	for(i=0; i<n; i++)
	{
	   scanf("%d", &arr[i]);
	}
	int key; 
    printf("Enter number to find its sum pairs:");
    scanf("%d", &key);
	i=0;
	int j = n-1, count =0;
	while(i < j)
	{
		if(arr[i]+arr[j] == key)
		{
			printf("%d is sum of %d and %d \n", key, arr[i], arr[j]);
			i++;
			j--;
            count++;
		}
		else if (arr[i]+arr[j] > key)
		{
	        j--;
		}
		else
        {
			i++;
		}
    }
    if(count == 0)
    {
        printf("No sum pair found!");
    }
}

/*
Problem: Find all pairs in a sorted array such that sum of elements of a pair is equivalent to given key using two pointer approach.

sample I/O:

Enter size of array:4
Enter sorted elements:1 2 3 4
Enter number to find its sum pairs:5
5 is sum of 1 and 4 
5 is sum of 2 and 3 

Enter size of array:5
Enter sorted elements:16 32 48 56 100
Enter number to find its sum pairs:80
80 is sum of 32 and 48 

Enter size of array:4
Enter sorted elements:5 6 7 8
Enter number to find its sum pairs:30
No sum pair found!

Time Complexity: O(n)
Space Complexity: O(1)
*/
