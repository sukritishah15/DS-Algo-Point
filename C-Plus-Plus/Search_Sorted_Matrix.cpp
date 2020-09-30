#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m, n, key, i, j;
    cout<<"Enter size of rows and columns:";
    cin>>m>>n;
    int arr[m][n];
    cout<<"Enter elements:"<<endl;
    for(i=0; i<m;i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"Enter element to be searched:";
    cin>>key;
    i = 0; 
    j = n-1;
    while((i < m) && (j >= 0))
    {
        if(arr[i][j] > key)
        {
            j--;
        }
        else if(arr[i][j] < key)
        {
            i++;
        }
        else
        {
            cout<<"Element found!"<<endl;
            return 0;
        }
    }
    cout<<"Element doesn't exist in matrix."<<endl;
	return 0;
}

/*
Problem: Find if an element x is present in a 2D matrix when matrix is sorted in increasing order both row and column wise.

sample I/O:

Enter size of rows and columns:3 4
Enter elements:
12 14 17 68
13 15 18 69
16 20 25 75
Enter element to be searched:19
Element doesn't exist in matrix.

Enter size of rows and columns:3 4
Enter elements:
12 14 17 68
13 15 18 69
16 20 25 75
Enter element to be searched:20
Element found!

Time Complexity:O(m+n)
Space complexity: O(1)
*/
