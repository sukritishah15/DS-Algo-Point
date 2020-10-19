/*Program to find the prefix sum of a array. Prefix sum is a method 
of dynamic programming to compute the value in O(n) operation one time and 
then use addition and subtraction to find other desired value in O(1)

Example of one such problem is range sum. If you are required to answer 
multiple queries on the sum of arr[l...k] then in such cases prefix array
can return the output in O(1)
*/
#include <stdio.h>
//basic function to create the prefix array
void findPrefixSum(int arr[], int n, int prefixSum[])
{
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
        //each element is added to the previous prefix sum to get current prefix sum
    }
}

/* update function is used to update one value in the original array 
and due to that one value change modify the prefix array
As one index will change value of multiple indices in prefix array this 
computation also requires O(n) time 
The function takes the index of the changed element , new value of the element
and the prefixsum array*/
void update(int index, int newValue, int prefixSum[], int n)
{
    int oldValue = prefixSum[index];
    prefixSum[index] = newValue;
    int diff = newValue - oldValue; // getting the difference betweeen the old element and the new element
    for (int i = index + 1; i < n; i++)
    {
        prefixSum[i] += diff; // adding the difference to each element after the current element
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int prefixSum[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    findPrefixSum(arr, n, prefixSum);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");
}

/*

Input : 4
        10 4 16 20
Output: 10 14 30 50
Complexity Analysis:

Time Complexity: O(n).
Auxiliary Space: O(n)

Update function Time complexity : O(n)
Update Function Space Complexity : O(1)

*/
