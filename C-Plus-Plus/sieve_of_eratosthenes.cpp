#include <bits/stdc++.h>
using namespace std;

// n is the upper limit to which primes are to be searched
void sieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime)); // assigning all the numbers as prime initially

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == true)
        {
            for (int k = i * i; k <= n; k += i)
            {
                prime[k] = false;
                // making all the multiples not prime
            }
        }
    }

    // function to print the primes
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
}

// main function goes here
int main()
{

    // input
    int n;
    cin >> n;
    sieveOfEratosthenes(n);
    return 0;
}

/*

User has to input the number n and the algorithm will give all the primes
smaller than or equal to n using Sieve of Eratosthenes.

Time complexity : O(n*log(log(n)))
Space complexity : O(n)

For example - 
Input: 4
Output : 2 3

Input : 10
Output: 2 3 5 7

*/