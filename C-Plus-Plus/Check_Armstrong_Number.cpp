#include <bits/stdc++.h> 
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number:";
    cin>>n;
    string str = to_string(n);
    int temp = n, sum = 0, rem, len = str.length();
    while(temp != 0)
    {
        rem = temp % 10;
        sum += pow(rem, len);
        temp = temp / 10;
    }
    if(n == sum)
    {
        cout<<n<<" is an armstrong number."<<endl;
    }
    else
    {
        cout<<n<<" is not an armstrong number."<<endl;
    }
    return 0;
}

/*
Problem: Check whether a given number is an armstrong number or not.

Sample I/O:
Enter a number:153
153 is an armstrong number.

Enter a number:247678687
247678687 is not an armstrong number.

Time Complexity: O(log N) (a number N has log N digits)
Space Complexity: O(1)
*/
