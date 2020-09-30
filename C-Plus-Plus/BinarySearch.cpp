#include <bits/stdc++.h>
using namespace std;

int Binarysearch(int arr[], int target, int l, int r)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == target)
        {
            return m;
        }

        if (arr[m] < target)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
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
    int index_found = Binarysearch(arr, target, 0, n - 1);
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
Time Complexity : O(logn)
Space Complexity : O(n)

User is required to enter the size of array and then elements of array
in a space seperated manner. At last the user has to enter the target value 
to be searched.

Input : 
5
1 2 3 4 5
3

Output : The number is found at index 2

Input :
5
1 2 3 4 5
6

Output : The number is not found
*/
