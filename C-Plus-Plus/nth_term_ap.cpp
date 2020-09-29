#include <iostream>
using namespace std;
int main(){
    int a1, a2, n;
    cout<<"Enter first term: ";
    cin>>a1;
    cout<<"Enter second term: ";
    cin>>a2;
    cout<<"Enter n: ";
    cin>>n;
    int d = a2 - a1;
    int tn = a1 + (n - 1) * d;
    cout<<tn;
    
    return 0;
}
/*
Problem:
Given the first two terms, a1 and a2, of an A.P. (Arithmetic Progression), and an integer n, find the value of nth term in the A.P.

For example -

Sample Input:
Enter first term: 2
Enter second term: 3
Enter n: 4

Sample Output:
5

Explanation:
The A.P. for this example would be - 2, 3, 4, 5, 6, 7, ...

Time complexity - O(1)
Space complexity - O(1)
*/