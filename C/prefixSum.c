/*Program to find the prefix sum of a array
*/
#include <stdio.h>
void findPrefixSum(int arr[], int n, int prefixSum[])
{
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

void update(int index, int newValue, int prefixSum[], int n)
{
    int oldValue = prefixSum[index];
    prefixSum[index] = newValue;
    int diff = newValue - oldValue;
    for (int i = index + 1; i < n; i++)
    {
        prefixSum[i] += diff;
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
