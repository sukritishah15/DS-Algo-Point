// This arena belongs to WhiteDeath99!

/*

Problem Statement

Given N books denoted by of an integer array A of N and B denoting the 
number of students. Each student would be allocated some number of pages to 
read, the A[i]'th entry denotes the number of pages in the
i'th book. Given these values minimise the maximum number of pages
allocated to a student.

Return -1 if a valid allocation is not possible.

Problem Tag - Binary Search the Answer

Constraint
N = [1, 10^5]

*/

#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> &A,int B,int m)
{
    int i,sum=0,student=1;
    for(i=0;i<A.size();i++)
    {
        if(A[i]>m)
            return false;
        if(A[i]+sum>m)
        {
            student++;
            sum=A[i];
            if(student>B)
                return false;
        }
        else
            sum+=A[i];
    }
    return true;
}

int main()
{

    int N,B;
    cin>>N>>B;
    vector<int> A(N);
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }

    int i,ans=INT_MAX;
    long long int s=0,e,m,sum=0;
    if(A.size()<B)
    {
        cout<<"-1";
        return 0;
    }
    for(i=0;i<A.size();i++)
        sum+=A[i];
    e=sum;
    while(e>=s)
    {
        m=(s+e)/2;
        if(possible(A,B,m))
        {
            ans=min(ans,(int)m);
            e=m-1;
        }
        else
            s=m+1;
    }
    cout<<ans;

}

/*

Sample Input 
4 2
12 34 67 90

Sample Output
113

Explanation

There are 2 number of students. Books can be distributed in following fashion : 

1) [12] and [34, 67, 90]
Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages

2) [12, 34] and [67, 90]
Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 

3) [12, 34, 67] and [90]
Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113.

*/