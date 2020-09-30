#include<bits/stdc++.h>

using namespace std;

void swap(int &a, int &b) 
{         
    //swap the content of a and b
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void display(int *arr, int size) 
{
    for(int i = 0; i<size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

void selectionSort(int *array, int size) 
{
    int i, j, imin;

    for(i = 0; i<size-1; i++) 
    {
        //get index of minimum data
        imin = i;   
        for(j = i+1; j<size; j++)
            if(array[j] < array[imin])
                imin = j;

        //placing in correct position
        swap(array[i], array[imin]);
    }
}

int main() 
{
    // size of array
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // create an array with given size taken as input
    int arr[n];  

    cout << "Enter elements: " << endl;
    for(int i = 0; i<n; i++) 
    {
        cin >> arr[i];
    }

    cout << "Array before Sorting: ";
    display(arr, n);

    // sorting the array 
    selectionSort(arr, n);

    cout << "Array after Sorting: ";
    display(arr, n);
}

/*
Sample I/P:
Enter the number of elements: 6
Enter elements:
9 11 5 7 4 10

Sample O/P:
Array before Sorting: 9 11 5 7 4 10
Array after Sorting: 4 5 7 9 10 11

Time Complexity: O(n^2)

Space Complexity: O(1)
*/
