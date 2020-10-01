#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int target, int size)
{
    for (int i = 0; i < size; i++)
    {
        // if the target value is found the algorithm returns the index
        if (arr[i] == target)
        {
            return i;
        }
    }
    // if the target value is not found then the algorithm returns -1
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    int index_found = search(arr, target, n);
    if (index_found == -1)
    {
        cout << "The number is not found\n";
    }
    else
    {
        cout << "The number is found at index " << index_found << endl;
    }
    return 0;
}

/*
Time Complexity : O(n)
Space Complexity : O(n)

The algorithm can also be solved in O(1) space if values 
are not stored in array

User is required to enter the size of array and then elements of array
in a space seperated manner. At last the user has to enter the target value 
to be searched.

Input : 
5
1 2 3 4 5
3

Output : The number is found at index 3

Input :
5
1 2 3 4 5
6

Output : The number is not found
*/
