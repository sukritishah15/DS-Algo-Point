//GCD of two Numbers Code

/*
Greatest Common Divisor of two numbers is the largest number that divides them both.
The most efficient way to solve this is using the Euclid's Algorithm, which says:
1. GCD(a,b) = GCD(b,a%b)
2. GCD(a,0) = a
*/

#include<bits/stdc++.h>
using namespace std;

int get_gcd(int num1, int num2)
{
    //swapping the numbers, thus making sure that num1 > num2
    if(num1<num2)
        swap(num1,num2);
    
    //Using the Euclid Algorithm stated above
    while(num2!=0)
    {
        int temp=num1%num2;
        num1=num2;
        num2=temp;
    }

    return num1;
}

int main()
{
    //Taking Inputs from the User
    int num1;
    cin>>num1;

    int num2;
    cin>>num2;

    //Calling get_gcd function and printing the GCD
    cout<<"The GCD of "<<num1<<" and "<<num2<<" is "<<get_gcd(num1,num2);

    return 0;
}

/*

Sample Input 1:
10
15

Sample Output 1:
The GCD of 10 and 15 is 5


Sample Input 2:
15
11

Sample Output 2:
The GCD of 15 and 11 is 1

*/

/* 

Time Complexity of this solution: O(log(min(num1,num2)))
Space Complexity of this solution: O(1)

*/
