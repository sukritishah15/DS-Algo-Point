// Collatz Sequence Code from scratch

/*
The Collatz conjecture is a conjecture in mathematics that concerns a sequence defined as follows: 
Start with any positive integer n, then each term is obtained from the previous term as follows: 
If the previous term is even, the next term is one half of the previous term. 
If the previous term is odd, the next term is 3 times the previous term plus 1. 
The conjecture is that the sequence will always reach 1 when n is positive, and will never reach otherwise.
*/

#include<bits/stdc++.h>
using namespace std;

void collatz_sequence(int n)
{
    
    if(n<=0)
    {
        cout<<"Collatz Sequence is not possible";
        return;
    }
    
    while(n!=1)
    {
        cout<<n<<" ";

        if(n%2==0)
            n=n/2;
        else
            n=3*n+1;
        
    }

    cout<<n;
}

int main()
{
    int n;
    cout<<"Enter any positive integer: ";
    cin>>n;

    cout<<"Printing Collatz Sequence: ";
    collatz_sequence(n);

    return 0;
}

/*
Sample Input 1:
12

Sample Output 1:
Printing Collatz Sequence: 12 6 3 10 5 16 8 4 2 1


Sample Input 2:
-12

Sample Output 2:
Printing Collatz Sequence: Collatz Sequence is not possible
*/

/*
There is no specific time of computing the collatz sequence of each numbers, so Time complexity is NA.

Time Complexity of solution: NA
Space Complexity of solution: O(1)
*/
