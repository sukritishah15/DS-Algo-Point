// This arena belongs to WhiteDeath99!

/*

You have an array P containing N non-negative integers. 
You have find the number of ways to split the array into 3 non-empty 
contigous subarrays, such that sum of elements in first subarray 
is less than or equal to sum of elements in the second subarray, 
and the sum of elements of second subarray is less than or equal 
to that of the third subarray

Problem Tag - Constructive + Binary Search

N = [1, 1e5]

*/

#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+5;

vector<int> pref(sz,0),suff(sz,0);
int n;

int last_time(int idx)
{
    int fsub=pref[idx];
    int lo=idx+1,hi=n-2;
    int ans=-1;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        int s=lo,t=hi;
        int ssub=pref[mid]-fsub;
        if(ssub>=fsub and ssub<=suff[mid+1])
        {
            ans=max(mid,ans);
            lo=mid+1;
        }
        else if(ssub>suff[mid+1])
        {
            hi=mid-1;
        }
        else if(ssub<fsub)
        {
            lo=mid+1;
        }
    }
    return ans;
}

int first_time(int X,int i)
{
    int mid; 
  
    int low = i+1; 
    int high = n-2; 
  
    while (low < high) 
    { 
        mid = low + (high - low) / 2; 
  
        if (X <= pref[mid]) 
        { 
            high = mid; 
        } 
  
        else 
        { 
            low = mid + 1; 
        } 
    } 
  
    return low; 
}

int main()
{
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    if(n<3)
    {
        cout<<"0";
        return 0;
    }
    if(n==3)
    {
        cout<<is_sorted(ar,ar+n);
        return 0;
    }

    pref[0]=ar[0];
    for(int i=1;i<n;i++)
    {
        pref[i]=ar[i]+pref[i-1];
    }

    suff[n-1]=ar[n-1];

    for(int i=n-2;i>=0;i--)
    {
        suff[i]=suff[i+1]+ar[i];
    }
    
    int ans=0;
    for(int i=0;i<n-2;i++)
    {
        int lpos=last_time(i);
        int num=2*pref[i];
        int fpos=first_time(num,i);
        if(lpos!=-1 and fpos!=n and fpos<=lpos)
            ans+=lpos-fpos+1;
    }

    cout<<ans;

}

/*

Sample Input
6
1 2 2 2 5 0

Sample Output
3

Explanation

The first possible segregation will be [1], [2], [2,2,5,0]

The second possible segregation will be [1], [2,2], [2,5,0]

The third possible segregation will be [1,2], [2,2], [5,0]


Time Complexity
Preprocessing - O(N)
Finding valid subsegments - O(N.log(N))

Space Complexity - O(N)

*/