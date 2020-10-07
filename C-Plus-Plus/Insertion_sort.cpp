//Insertion sort

#include <bits/stdc++.h>

using namespace std;

//Insertion sort Function
void insertionSort(int arr[], int n)
{
    int num, j;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        num = arr[i];
        while (j >= 0 && arr[j] > num)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = num;
    }
}

//Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nArray before sorting: ";
    printArray(arr, n);
    cout << "Array after sorting: ";
    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}

/*
INPUT:
Enter the number of elements: 5
Enter the elements: 5 6 0 -7 54
OUTPUT
----------------
Array before sorting: 5 6 0 -7 54 
Array after sorting: -7 0 5 6 54
----------------
Time complexity of Insertion sort : O(n^2)
Auxiliary Space complexity of Insertion sort : O(1)
*/
