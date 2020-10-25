#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, cnt=0;
    cout<<"Enter any number:";
    cin>>n;
    while((n != 1) && (n != 0))
    {
        if((n%2) == 1)
        {
            cnt++;
        }
        n = n/2;
    }
    if(n==1)
    {
        cnt++;
    }
    if((cnt%2) == 0)
    {
        cout<<"It is an evil number"<<endl;
    }
    else
    {
        cout<<"It is not an evil number"<<endl;
    }
    return 0;
}

/*
Problem: Check if a number is evil or not. An evil number has even number of 1s in its binary representaton.
-> Divide number by 2 until it is 1 or 0. Check remainder everytime, if it is 1 then increase the count.

Sample I/O:

Enter any number:129
It is an evil number

Enter any number:32
It is not an evil number

Time Complexity: O(logn) where n is the given number
Space complexity: O(1)
*/
