#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size_arr)
{
    int i, j;
    for(i = 0; i < size_arr-1; ++i)
    {
        for(j = 0; j < size_arr-1-i; ++j)
        {
            if(arr[j+1] < arr[j])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void printArray(int arr[], int size_arr)
{
    for(int i = 0; i < size_arr; ++i)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int flag = 0, size_arr, i, num;
    int arr[] = {19, 7, -5, 6, 0, 8};
    size_arr = sizeof(arr)/sizeof(arr[0]);

    /* Check if array is already sorted,
        thus making time complexity = O(n)
    */

    for(i = 0; i < size_arr-1; ++i)
    {
        if(arr[i+1] < arr[i])
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        cout<<"\nSorted Array: ";
        bubbleSort(arr, size_arr);
    }
    else
    {
        cout<<"\nData is already sorted: ";
    }

    printArray(arr, size_arr);

    return 0;
}

/*
Bubble Sort implementation in C++
Input: Array of integers
Output: Sorted array in ascending order
----------------------------------------
Sample Input:
[19, 7, -5, 6, 0, 8]
Output:
Sorted Array: -5 0 6 7 8 19
----------------------------------------

Time Complexity:
Worst and Average case = O(n^2)
Best case (when array is already sorted) = O(n)

Space Complexity: O(1)

*/
