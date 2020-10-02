#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucketSort(vector<float> &arr, int n)
{
    vector<float> b[n];

    for (int i=0; i<n; i++)
    {
       int x = n*arr[i];
       b[x].push_back(arr[i]);
    }

    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];
}

int main()
{
    int n;
    cout<<"Enter no of Elements: ";
    cin>>n;
    cout<<"\nEnter Elements";
    vector<float> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\nBefore Sorting\n";
    for (int i=0; i<n; i++)
    cout << arr[i] << " ";

    bucketSort(arr, n);

    cout << "\nAfter Sorting \n";
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}

/*
Worst Case Complexity: O(n2)
Best Case Complexity: O(n+k)
Average Case Complexity: O(n)
Space Complexity: O(n+k)
Input and Output:
Enter no of Elements: 8
Enter Elements
0.235
0.101
0.476
0.7645
0.15
0.142
0.7845
0.4545
Before Sorting:
0.235 0.101 0.476 0.7645 0.15 0.142 0.7845 0.4545
After Sorting
0.101 0.142 0.15 0.235 0.4545 0.476 0.7645 0.7845
*/
