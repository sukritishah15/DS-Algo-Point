#include <stdio.h>
//Radix Sort Uses Counting Sort as a Subroutine.
int calculateMax(int a[], int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
void count_sort(int a[], int n, int pos)
{
    int count[10] = {0};
    int b[n];
    for (int i = 0; i < n; i++)
    {
        ++count[(a[i] / pos) % 10];
    }
    for (int i = 1; i <= 9; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        b[--count[(a[i] / pos) % 10]] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}

void radix_sort(int a[], int n)
{
    int max = calculateMax(a, n);
    for (int position = 1; max / position > 0; position *= 10)
    {
        count_sort(a, n, position);
    }
}

int main()
{
    printf("Enter the Number of Elements: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    radix_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
/*
Sample Input
  10
  543 432 13 6 1 4567 45613 521 37 22
Sample Output
    1 6 13 22 37 432 521 543 4567 45613
________________________________________________
Time Complexity: O(d*(n+k)) where 'd' is the number of digits in max,k is 9
Space Complexity:O(n+k) because we are using extra space for count array
*/
