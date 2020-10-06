#include<stdio.h>
void main()
{
    int n, i, k;
    printf("Enter size of array:");
    scanf("%d", &n);
    int arr[n], ans[n];
    printf("Enter elements:");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Rotate array by how many elements:");
    scanf("%d", &k);
    int j = k;
    if(j>=n)
    {
        j = j%n;
    }
    for(i=0; i<n; i++, j++)
    {
        if(j==n)
        {
            j=0;
        }
        ans[j] = arr[i];
    }
    printf("Rotated array is \n");
    for(i=0; i<n; i++)
    {
        printf("%d ",ans[i]);
    }
}

/*
Problem: Rotated an array by given k elements in clockwise manner.

Sample I/O:

Enter size of array:4
Enter elements:1 2 3 4
Rotate array by how many elements:15
Rotated array is 
2 3 4 1 

Enter size of array:5
Enter elements:1 2 3 4 5
Rotate array by how many elements:2
Rotated array is 
4 5 1 2 3

Time Complexity: O(n)
Space Complexity : O(n)
*/
