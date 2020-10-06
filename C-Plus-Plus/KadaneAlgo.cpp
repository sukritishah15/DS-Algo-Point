#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long ll;

ll kadane(vector<ll> &arr,int &n) {
    ll best = 0,sum =0;
    for(int i=0;i<n;i++) {
        sum = max(arr[i],sum+arr[i]);
        best = max(best,sum);
    }
    return best;

}

int main()
{
    int n;//Size of the array.
    cin>>n;
    vector<ll> arr(n);//Array of the input size
    for(int i=0;i<n;i++) {
        cin>>arr[i];//Inputs to the array.
    }
    cout<<kadane(arr,n)<<endl;//Finally the result.
    return 0;
}
/*
    Name of Algorithm : Kadane's Algorithm
    Time Complexity : O(n)
    Space Complexity : O(1)

    User is required to enter the size of the array and
    then elements of the array in a space required manner.
    Then after giving proper inputs then the  maximum
    contiguous sum of the subarray will be printed.


    Input :
    8
    -2 -3 4 -1 -2 1 5 -3

    Output :
    7


    Explanation :
    4 + (-1) + (-2) + 1+ 5 = 7
*/

